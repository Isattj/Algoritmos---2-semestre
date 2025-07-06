#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include <time.h>

struct Point {
    float x;
    float y;
};
typedef struct Point Point;

struct contact {
    int id;
    char name[51];
    char email[51];
    int type;
};
typedef struct contact Contact;

struct employee{
    char name[50];
    float salary;
    int type;
};
typedef struct employee Employee;

float print_point(Point p){
    printf("Ponto (%.2f, %.2f)\n", p.x, p.y);
    return 0;
}

float distance2D(Point p1, Point p2){
    float distance;
    float xq = (p2.x - p1.x) * (p2.x - p1.x);
    float yq = (p2.y - p1.y) * (p2.y - p1.y);
    distance = sqrt(xq + yq);
    return distance;
}

float distance_vector(int n, Point v[]){
    float distance = 0;
    for (int i = 0; i < n - 1; i++){
        distance = distance2D(v[i], v[i+1]);
        printf("Distancia entre Ponto %d e Ponto %d: %.2f\n", i, i+1, distance);
    }
    return 0;
}

void random_points(int n, Point v[]){
    for(int i = 0; i < n; i++){
        float x = rand()/(float)RAND_MAX;
        v[i].x = x * 100 - 50;
        
        float y = rand()/(float)RAND_MAX;
        v[i].y = y * 100 - 50;
        print_point(v[i]);
    }
}

void nearest_points(int n, Point v[]){
    float min_distancia1 = FLT_MAX;
    float pont1 = 0;
    float pont2 = 0;

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            float dist_temp = distance2D(v[i], v[j]);
            if (dist_temp < min_distancia1){
                min_distancia2 = min_distancia1;
                min_distancia1 = dist_temp;

            } else if (dist_temp < min_distancia2 && dist_temp > min_distancia1){
                min_distancia2 = dist_temp;
            }
        }
    }
    printf("Menor distancia: %.2f\n", min_distancia1);
    printf("Segunda menor distancia: %.2f\n", min_distancia2);
}

void print_contact(Contact c, int n, char type_names[n][50]){
    int type = c.type;
    char type2[50];
    strcpy(type2, type_names[type]);
    printf("{%d, %s, %s, %s}\n", c.id, c.name, c.email, type2);
}

void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][50]){
    for (int i = 0; i < n2; i++){
        int found = 0;
        for (int j = 0; j < n1; j++){
            if (list[j].type == i){
                if (found == 0){
                    printf("%s\n", types[i]);
                    found = 1;
                }
                printf("%s\n", list[j].name);
            }
        }
        printf("\n");
    }
}

void print_best3(int n, Employee v[n]){
    float salario1 = FLT_MIN;
    float salario2 = FLT_MIN;
    float salario3 = FLT_MIN;
    int sal1 = -1;
    int sal2 = -1;
    int sal3 = -1;
    for (int i = 0; i < n; i++){
        if(v[i].salary > salario1){
            salario3 = salario2;
            sal3 = sal2;
            salario2 = salario1;
            sal2 = sal1;
            salario1 = v[i].salary;
            sal1 = i;
        } else if(v[i].salary > salario2){
            salario3 = salario2;
            sal3 = sal2;
            salario2 = v[i].salary;
            sal2 = i;
        } else if(v[i].salary > salario3){
            salario3 = v[i].salary;
            sal3 = i;
        }
    }
    printf("%s: %.2f \n", v[sal1].name, v[sal1].salary);
    printf("%s: %.2f \n", v[sal2].name, v[sal2].salary);
    printf("%s: %.2f \n", v[sal3].name, v[sal3].salary);
}

void income_report(int n, Employee v[n]){
    float sDeve = 0;
    float sDesi = 0;
    float sMana = 0;
    float sSupp = 0;
    int contDeve = 0;
    int contDesi = 0;
    int contMana = 0;
    int contSupp = 0;
    for(int i = 0; i < n; i++){
        if (v[i].type == 0){
            sDeve += v[i].salary;
            contDeve++;
        } else if (v[i].type == 1){
            sDesi += v[i].salary;
            contDesi++;
        } else if (v[i].type == 2){
            sMana += v[i].salary;
            contMana++;
        } else if (v[i].type == 3){
            sSupp += v[i].salary;
            contSupp++;
        }
    }

    float salarioT = sDeve + sDesi + sMana + sSupp;
    printf("Salario total: %.2f\n", salarioT);

    float mediaT = salarioT / n;
    printf("Media de salarios: %.2f\n", mediaT);

    float mediaDeve = sDeve / contDeve;
    printf("Media de salarios dos Developers: %.2f\n", mediaDeve);

    float mediaDesi = sDesi / contDesi;
    printf("Media de salarios dos Designers: %.2f\n", mediaDesi);

    float mediaMana = sMana / contMana;
    printf("Media de salarios dos Managers: %.2f\n", mediaMana);

    float mediaSupp = sSupp / contSupp;
    printf("Media de salarios dos Support: %.2f\n", mediaSupp);
}

void fix_name(char name[]){
    //remove os simbolos que não são letras
    for(int i = 0; name[i] != '\0'; i++){
        if(!isLetter(name[i])){
            name[i] = ' '; 
        }
    }

    //remover espaços excedentes
    char aux[strlen(name)+1];
    int k = 0;
    for (int i = 0; name[i] != '\0'; i++){
        if(name[i] != ' '){ //encontramos o inicio de uma palavra e move a palavra para a nova string

            while (name[i] != ' ' && name[i] != '\0'){
                aux[k] = name[i];
                k++;
                i++;
            }
            aux[k] = ' ';
            k++;
            i--;
        }
    }
    aux[k-1] = 0;

    strcpy(name, aux);

    //Colocando as primeiras letras em maiuscula e as outras em minuscula
    int palavra = 1;
    for(int i = 0; i < strlen(name); i++){
        if (name[i] >= 'a' && name[i] <= 'z'){
            if (palavra == 1){
                name[i] -= 32;
                palavra = 0;
            }
        } else if (name[i] >= 'A' && name[i] <= 'Z'){
            if (palavra == 0){
                name[i] += 32;
            } else{
                palavra = 0;
            }
        } else if (name[i] == ' '){
            palavra = 1;
        }
    }
}

Contact create_contact(int id, char name[], int type){
    Contact c;
    c.id = id;

    strcpy(c.name, name);

    char nameE[51];
    strcpy(nameE, name);
    for (int i = 0; i < strlen(nameE); i++){
        if (nameE[i] == ' '){
            nameE[i] = '.';
        }
    }
    
    strcat(nameE, "@mail.br");
    strcpy(c.email, nameE);

    c.type = type;
    return c;
}

void fill_contact_list(int n, Contact list[n]){
    int cont = 0;
    srand(time(NULL));
    for (int i = 0; i < n; i ++){
        list[i].id = cont++;

        char name[51];
        printf("Digite o nome do contato %d: \n>", cont);
        scanf(" %[^\n]", name);
        fix_name(name);
        strcpy(list[i].name, name);

        char word[4] = "Doe";

        char email[51];
        strcpy(email, name);
        for (int j = 0; j < strlen(email); j++){
            if(email[j]==' '){
                email[j] = '.';
            }
        }
        strcat(email, "@mail.br");
        strcpy(list[i].email, email);

        if (strstr(name, word) != NULL){
            list[i].type = 1;
        } else{
            list[i].type = rand() % 5;
        }

        printf("%d, %s, %s, %d\n", list[i].id, list[i].name, list[i].email, list[i].type);
    }
}

int find_by_name(int n1, Contact list[n1], int n2, char names[n2][50]){
    int cont = 0;

    for(int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            fix_name(names[j]);
            if (strstr(list[i].name, names[j]) != NULL){
                cont++;
            }
        }
    }
    return cont;
}

int main(){
    int e = 0;
    printf("Escolha o exercicio: \n>");
    scanf("%d", &e);
    switch (e)
    {
    case 1:{
        Point p;
        p.x = 1.5;
        p.y = 2.5;
        print_point(p);
        break;
    }
    case 2:{
        Point p1, p2;
        p1.x = 2.0;
        p1.y = 7.5;
        p2.x = 5.0;
        p2.y = 12.4;
        float dist = distance2D(p1, p2);
        printf("Distância: %.2f\n", dist);
        break;
    }
    case 3:{
        Point pontos[4] = {
        {5.0, 0.0},
        {3.0, 4.0},
        {7.5, 8.0},
        {9.0, 12.0}
        };

        distance_vector(4, pontos);
        break;
    }
    case 4:{
        Point pontos[4];
        random_points(4, pontos);
        break;
    }
    case 5:{
        Point pontos[4] = {
        {5.0, 0.0},
        {3.0, 4.0},
        {7.5, 8.0},
        {9.0, 12.0}
        };

        nearest_points(4, pontos);
        break;
    }
    case 6:{
        char types[5][50] = {"Família","Amigos","Trabalho","Escola","Outros"};
        Contact c = {1, "John Doe", "john.doe@email.com", 0};
        print_contact(c, 5, types);
        break;
    }
    case 7:{
        char types[][50] = {"Família","Amigo","Trabalho","Escola","Outros"};
        Contact list[] = {
            {1, "Marcus Fenix", "fenix@gow.com", 2},
            {41,"Blue Mary", "mary@ff3snk.net", 0},
            {17,"Barry Burton", "bburton@re.cap", 0},
            {8, "Charlie Nash", "nash@ssz.com", 2},
            {2, "Ada Wong", "wong@re2.net", 4},
            {5, "Chris Redfield", "crfield@re.cap", 0}
        };
        print_contact_list(6, list, 5, types);
        break;
    }
    case 8:{
        Employee list[] = {
            {"Marcus Fenix", 15000.00, 2},
            {"Blue Mary", 8000.00, 0},
            {"Barry Burton", 1500.00, 0},
            {"Charlie Nash", 2000.00, 1},
            {"Ada3Wong", 10000.00, 3},
            {"Chris Redfield", 5000.00, 0}
        };
        print_best3(6, list);
        break;
    }
    case 9:{
        Employee list[] = {
            {"Marcus Fenix", 15000.00, 2},
            {"Blue Mary", 8000.00, 0},
            {"Barry Burton", 1500.00, 0},
            {"Charlie Nash", 2000.00, 1},
            {"Ada3Wong", 10000.00, 3},
            {"Chris Redfield", 5000.00, 0}
        };
        income_report(6, list);
        break;
    }
    case 10:{
        char name[] = " JoHN  DOE    23#";
        fix_name(name);
        break;
    }
    case 11:{
        Contact x;
        strcpy(x.name, " JoHn! Do5e3 SILVA");
        fix_name(x.name);
        Contact c = create_contact(4, x.name, 1);
        printf("%d, %s, %s, %d\n", c.id, c.name, c.email, c.type);
        break;
    }
    case 12:{
        Contact list[3];
        fill_contact_list(3, list);
        break;
    }
    case 13:{
        Contact list[3] = {
            {1, "John Doe", "john.doe@mail.br", 1},
            {2, "Leonor Garcia", "leonor.garcia@mail.br", 2},
            {3, "Mike Tyson", "mike.tyson@mail.br", 0}
        };

        char names[5][50] = {"joanna", "john", "mike", "leonor", "caroline"};

        int count = find_by_name(3, list, 5, names);

        printf("Quantidade de contatos encontrados: %d\n", count);
        break;
        }
    default:
        break;
    }
    return 0;
}