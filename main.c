#include <stdio.h>
#include <stdlib.h>

int createFile(char filepath[], char fileContent[]){

        FILE *f;
        f =  fopen(filepath,"w");
        fputs(fileContent, f);
        fclose(f);

        return 0;
}

int removeFile(char* filepath){
        return remove(filepath);
}

int copyFile(char* filepath, char* newpath){

        FILE *oldf, *newf;

        if(!(oldf =  fopen(filepath,"rb"))) {
                printf("%s\n", "File do not exist");
                return -1;
        }

        newf = fopen(newpath,"wb");

        int c;
        while((c = fgetc(oldf)) != EOF) {
                fputc(c, newf);
        }

        fclose(oldf);
        fclose(newf);
        return 0;
}

int moveFile(char* filepath, char* newpath){
        if(copyFile(filepath, newpath) != 0) {
                printf("%s\n", "File do not exist");
                return -1;
        }
        removeFile(filepath);
        return 0;
}

int renameFile(char* filepath, char* newName){
        return moveFile(filepath, newName);
}

int appendTextEnd(char* filepath, char* text){
        FILE *f;
        if(!(f = fopen(filepath, "a"))) {
                printf("%s\n", "File do not exist");
                return -1;
        }
        fputs(text, f);
        fclose(f);
        return 0;
}

int appendPosition(char* filepath, char* text, int position){
        FILE *f;

        if(!(f = fopen(filepath, "r")))
        {
                printf("%s\n", "File do not exist");
                return -1;
        }
        fseek(f, 0, SEEK_END);
        size_t length = ftell(f);
        fseek(f, 0, SEEK_SET);

        if (length < position) {
                printf("%s\n", "given position is less than length of file" );
                return -1;
        }

        if (position < 0) {
                printf("%s\n", "position is less than zero" );
                return -1;
        }

        char current[length], c;
        int count;

        for(count=0; (c = fgetc(f)) != EOF; ++count) {
                current[count] = c;
        }
        fclose(f);

        f = fopen(filepath, "w+");
        for(count=0; position > count; ++count) {
                fputc(current[count], f);
        }
        for(count=0; text[count]!='\0'; ++count) {
                fputc(text[count], f);
        }
        for(count=position; count<length; ++count) {
                fputc(current[count], f);
        }
        fclose(f);

        return 0;
}

int removeAllText(char* filepath){
        FILE *f;
        if(!(f =  fopen(filepath,"r"))) {
                printf("%s\n", "File do not exist");
                return -1;
        }

        f =  fopen(filepath, "w");
        fputs("", f);
        fclose(f);
        return 0;
}

int readPages(char filepath[], int pages){
        FILE *f;
        char c;
        int count1 = 0;
        if(!(f = fopen(filepath, "r"))) {
                printf("%s\n", "File do not exist");
                return -1;
        }

        while((c = fgetc(f)) != EOF) {
                printf("%c", c);

                if(c == '\n') {
                        if (++count1 == pages) {
                                do {
                                        char p;
                                        p = getchar();
                                        if (p == 'n')
                                                break;
                                } while(1);
                                count1 = 0;
                        }
                }
        }
        fclose(f);

        return 0;
}

int fimanuCLI()
{
        char userCommmand[80];
        char param1[80];
        char param2[80];
        int param3;
        int result;

        printf("%c", '>');
        scanf("%s", userCommmand);

        if(!strcmp(userCommmand,"createFile"))
        {
                printf("%s", "file name >");
                scanf(" %[^\n]s", param1);

                printf("%s", "content name >");
                scanf(" %[^\n]s", param2);

                return createFile(param1, param2);
        }

        else if(!strcmp(userCommmand,"removeFile"))
        {
                printf("%s", "file name >");
                scanf(" %[^\n]s", param1);
                return removeFile(param1);
        }

        else if(!strcmp(userCommmand,"copyFile"))
        {
                printf("%s", "file path >");
                scanf(" %[^\n]s", param1);

                printf("%s", "new file path >");
                scanf(" %[^\n]s", param2);

                return copyFile(param1, param2);
        }

        else if(!strcmp(userCommmand,"moveFile"))
        {
                printf("%s", "file path >");
                scanf(" %[^\n]s", param1);

                printf("%s", "new file path >");
                scanf(" %[^\n]s", param2);

                return moveFile(param1, param2);
        }

        else if(!strcmp(userCommmand,"renameFile"))
        {
                printf("%s", "file path >");
                scanf(" %[^\n]s", param1);

                printf("%s", "new name >");
                scanf(" %[^\n]s", param2);

                return renameFile(param1, param2);
        }
        else if(!strcmp(userCommmand,"appendTextEnd"))
        {
                printf("%s", "file path >");
                scanf(" %[^\n]s", param1);

                printf("%s", "text that you want to add >");
                scanf(" %[^\n]s", param2);

                return appendTextEnd(param1, param2);
        }
        else if(!strcmp(userCommmand,"appendPosition"))
        {
                printf("%s", "file path >");
                scanf("%s", param1);

                printf("%s", "text that you want to add >");
                scanf(" %[^\n]s", param2);

                printf("%s", "position >");
                scanf("%d", &param3);

                return appendPosition(param1, param2,param3);
        }

        else if(!strcmp(userCommmand,"removeAllText"))
        {
                printf("%s", "file path >");
                scanf("%s", param1);

                return removeAllText(param1);
        }

        else if(!strcmp(userCommmand,"readPages"))
        {
                printf("%s", "file path >");
                scanf("%s", param1);

                printf("%s", "number of pages >");
                scanf("%d", &param3);

                return readPages(param1,param3);
        }
        else if(!strcmp(userCommmand,"help")) {
                printf("%s\n", "createFile \n\t this command create file \n");
                printf("%s\n", "removeFile \n\t this command remove file \n");
                printf("%s\n", "copyFile \n\t this command copy file \n");
                printf("%s\n", "moveFile \n\t this command move file \n");
                printf("%s\n", "renameFile \n\t this command rename file \n");
                printf("%s\n", "appendTextEnd \n\t this command append text to end of file \n");
                printf("%s\n", "appendPosition \n\t this command append text to given position of file \n");
                printf("%s\n", "removeAllText \n\t this command remove all text \n");
                printf("%s\n", "readPages \n\t this command print file as given pages \n");
        }
        else{
                printf("No command like that place check help if you need...\n");
        }
        return 0;
}


int main() {
        while(1)
                fimanuCLI();
}
