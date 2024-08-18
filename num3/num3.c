#include "num3.h"

int open_file(const char *file_path){
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Ошибка при открытии файла");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
            count++;
        }
    fclose(file);
    return count;
}

void generate_dict_from_file(const char *file_path,int count) {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(file_path, "r");
    Dict dict[count];
    int i = 0;
    
    while (fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\n")] = 0;
        char *first_word = strtok(line, " ");
        char *rest_of_line = strtok(NULL, "");

        if (first_word != NULL && rest_of_line != NULL) {
            strncpy(dict[i].key, first_word, MAX_WORD_LENGTH - 1);
            strncpy(dict[i].value, rest_of_line, MAX_LINE_LENGTH - MAX_WORD_LENGTH - 1);
        }
        i++;
    }

    if (count >= 0) {
        printf("Словарь:\n");
        printf("{");
        for (int i = 0; i < count; i++) {
            if (i != count - 1) printf("\"%s\": \"%s\", ", dict[i].key, dict[i].value);
            else printf("\"%s\": \"%s\"", dict[i].key, dict[i].value);
        }
        printf("}\n");
    }
    fclose(file);
}

int main() {
    char file_path[20];
    printf("Vvedite nazvanie faila: \n");
    fgets(file_path,sizeof(file_path),stdin);
    file_path[strcspn(file_path,"\n")] = '\0';

    int dict_size = open_file(file_path);

    if (dict_size != -1) generate_dict_from_file(file_path, dict_size);

    return 0;
}