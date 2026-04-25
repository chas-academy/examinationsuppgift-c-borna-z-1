#include <stdio.h>
#include <ctype.h>

#define STUDENTS 5
#define TEST 13
#define NAME_LEN 11

void capitalize (char name[]){
    if(name[0] != '\0'){
        name[0] = toupper(name[0]);
    }

    for (int i = 1; name[i] != '\0'; i++){
        name[i] = tolower(name[i]);
    }

}

int main () {
    char names[STUDENTS][NAME_LEN];
    int scores[STUDENTS][TEST];
    double averages[STUDENTS];

    int best_index = 0;
    double best_average = 0.0;
    double group_average = 0.0;

    for (int i = 0; i < STUDENTS; i++){
        int sum = 0;

        scanf ("%10s", names[i]);

        for (int j = 0; j < TEST; j++){
            scanf("%d", &scores[i][j]);
            sum += scores[i][j];
        }

        averages[i] = sum / (double)TEST;
        group_average += averages[i];

        if (i  == 0 || averages[i] > best_average){
            best_average = averages[i];
            best_index = i;
        }
    }

    group_average /= STUDENTS;

    capitalize(names[best_index]);
    printf("%s\n", names[best_index]);

    for (int i = 0; i < STUDENTS; i++){
        if (averages[i] < group_average){
            capitalize(names[i]);
            printf("%s\n", names[i]);
        }
    }
    return 0;
}

//här är min lösning.
// progrmammet läser in namn och poäng för 5 studenter,
//beräknar genomsnittet för varje student och det högsta genomsnittet,
// och sedan skriver ut namnet på den student som har det högsta genomsnittet, samt namnen på de studenter som har ett genomsnitt under gruppens genomsnitt.
<3