#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[51];
} Movie;

void print_array(int n, int* v){
    for(int i = 0; i < n; i++){
        printf("%d ", *(v+i));
    }
    printf("\n");
}


void write_array(const char* filepath, const int* v, int n){
    FILE* file = fopen(filepath,  "a");
    fwrite(v, sizeof(int), n, file);
}

int* read_array(const char* filepath, int* n){
    FILE* file = fopen(filepath, "rb");

    if(file ==  NULL) return NULL;

    fseek(file, 0, SEEK_END);
    *n = ftell(file)/sizeof(int);
    fseek(file, 0, SEEK_SET);

    int* v = malloc(*n * sizeof(int));

    fread(v, sizeof(int), *n, file);
    return v;
}


void write_all_movies(const char* filepath, const Movie* list, int n){
    FILE* file = fopen(filepath, "wb");

    fwrite(list, sizeof(Movie), n, file);
}

int count_movies(const char* filepath){
    FILE* file = fopen(filepath, "rb");

    Movie *list;
    int lidos = 0;
    while(fread(list, sizeof(Movie), 1, file) == 1){
        lidos++;
    }

    fclose(file);
    return lidos;
}


Movie read_movie(const char* filepath, int pos){
    FILE* file = fopen(filepath, "rb");

    Movie m = {0};

    if(fseek(file, pos * sizeof(Movie), SEEK_SET) != 0){
        fclose(file);
        return m;
    }

    fread(&m, sizeof(Movie), 1, file);

    fclose(file);
    return m;
}

int find_movie(const char* filepath, long id){
    FILE* file = fopen(filepath, "rb");

    if(file == NULL) return -1;

    int pos = 0;
    Movie m;

    while(fread(&m, sizeof(Movie), 1, file) == 1){
        if(m.id == id){
            fclose(file);
            return pos;
        }
        pos++;
    }

    fclose(file);
    return -1;
}

int add_movie(const char* filepath, const Movie* movie){
    FILE* file = fopen(filepath, "ab");
    if(file == NULL) return 0;

    fwrite(movie, sizeof(Movie), 1, file);
    fclose(file);
    return 1;
}

int update_movie(const char* filepath, const Movie* movie){
    int pos = find_movie(filepath, movie->id);
    if(pos == -1) return 0;

    FILE* file = fopen(filepath, "r+b");
    if(file == NULL) return 0;

    fseek(file, pos * sizeof(Movie), SEEK_SET);

    fwrite(movie, sizeof(Movie), 1, file);
    return 1;
}

int delete_movie(const char* filepath, long id){
    int pos = find_movie(filepath, id);
    if(pos == -1) return 0;

    Movie m = read_movie(filepath, pos);
    m.id = -1;

    FILE* file = fopen(filepath, "r+b");
    if(file == NULL) return 0;

    fseek(file, pos * sizeof(Movie), SEEK_SET);
    fwrite(&m, sizeof(Movie), 1, file);

    fclose(file);
    return 1;
}

int insert_sorted(const char* filepath, const Movie* movie){
    FILE* file = fopen(filepath, "r+b");
    if(file == NULL) return 0;

    Movie m;
    int pos = 0;
    int pos_inserir = -1;

    while(fread(&m, sizeof(Movie), 1, file) == 1){
        if(m.id > movie->id){
            pos_inserir = pos;
            break;
        }
        pos++;
    }

    if(pos_inserir == -1){
        fseek(file, 0, SEEK_END);
        fwrite(movie, sizeof(Movie), 1, file);
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int tamanho = ftell(file) / sizeof(Movie);

    for(int i = tamanho - 1; i >= pos_inserir; i--){
        fseek(file, i * sizeof(Movie), SEEK_SET);
        fread(&m, sizeof(Movie), 1, file);

        fseek(file, (i + 1) * sizeof(Movie), SEEK_SET);
        fwrite(&m, sizeof(Movie), 1, file);
    }

    fseek(file, pos_inserir * sizeof(Movie), SEEK_SET);
    fwrite(movie, sizeof(Movie), 1, file);

    fclose(file);
    return 1;
}

int defrag(const char* filepath){
    FILE* file = fopen(filepath, "r+b");
    if(file == NULL) return 0;

    FILE* temp = fopen("temp.bin", "wb");
    if (!temp) {
        fclose(file);
        return 0;
    }

    Movie m;
    int valido = 0;
    

    while(fread(&m, sizeof(Movie), 1, file) == 1){
        if(m.id != -1){
            fwrite(&m, sizeof(Movie), 1, temp);
            valido = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(filepath);
    rename("temp.bin", filepath);

    return 1;
}

int main(){
int e = 0;
    printf("Escolha o exercicio: \n>");
    scanf("%d", &e);
    switch (e)
    {
        case 1:{
            int v[] = {1,2,3,4,5,6,7,8,9,10};
            write_array("dados.bin", v, 10);
            break;
        }
        case 2:{
            int n;            
            int* v = read_array("dados.bin", &n);
            print_array(n, v);
            free(v);
            break;

        }
        case 3:{
            Movie list[] = {
            {6, "They Live"},
            {11,"Big Trouble in Little China"},
            {10,"The Thing"},
            {1, "In the Mouth of Madness"},
            {8, "Ghosts of Mars"},
            {23,"Halloween"},
            {7, "Village of the Damned"}
            };
            // cria arquivo 'dados.bin' com conteúdo de 'list'
            write_all_movies("movies.bin", list, 7);
            break;

        }
        case 4:{
            int size = count_movies("movies.bin");
            printf("%d", size);
            break;
        }
        case 5:{
            Movie movie = read_movie("movies.bin", 7);
            printf("ID: %d\nTitulo: %s\n", movie.id, movie.name);
            break;
        }
        case 6:{
            long pos = find_movie("movies.bin", 23);
            printf("%d", pos);
            break;
        }
        case 7:{
            Movie v = {63, "How To Trin Your Dragon"};
            long r = add_movie("movies.bin", &v);
            printf("%d", r);
            break;
        }
        case 8:{
            Movie v = {63, "How To Train Your Baby"};
            long r = update_movie("movies.bin", &v);
            printf("%d", r);
            break;
        }
        case 9:{
            long r = delete_movie("movies.bin", 63);
            printf("%d", r);
            break;
        }
        case 10:{
            Movie v = {9, "aaaaa"};
            long r = insert_sorted("movies.bin",&v);
            printf("%d", r);
            break;
        }
        case 11:{
            long r = defrag("movies.bin");
            printf("%d", r);
            break;
        }
        default:
            break;
    }
    return 0;
}