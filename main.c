#include <stdio.h>

void createFile(char* filepath,char* fileContent){
  FILE *f;
  f =  fopen(filepath,"w");
  fputs(fileContent, f);
  fclose(f);
}

int removeFile(char* filepath){
  return remove(filepath);
}

void copyFile(char* filepath, char* newpath){
  FILE *oldf;
  // error is not exist file
  oldf =  fopen(filepath,"r");

  FILE *newf;
  newf = fopen(newpath,"w");
  char c;

  while((c = fgetc(oldf)) != EOF) {
    fputc(c, newf);
  }
}

void moveFile(char* filepath,char* newpath){
  copyFile(filepath, newpath);
  removeFile(filepath);
}

void renameFile(char* filepath, char* newName){
  // i will implement that
  moveFile(filepath, newName);
}

void appendTextEnd(char* filepath, char* text){
	FILE *f;
	f = fopen(filepath, "a");
	fputs(text, f);
	fclose(f);
}

int appendPosition(char* filepath, char* text, int position){
	FILE *f;
	f = fopen(filepath, "r");
  fseek(f, 0, SEEK_END);
	size_t length = ftell(f);
  fseek(f, 0, SEEK_SET);

  if (length < position){
    return -1; //given position is less than length of file
  }
  if (position < 0){
    return -2; //position is less than zero
  }

  char current[length], c;
  int count;

  for(count=0; (c = fgetc(f)) != EOF; ++count){
    current[count] = c;
  }
	fclose(f);

  f = fopen(filepath, "w+");
  for(count=0; position > count; ++count){
    fputc(current[count], f);
  }
  for(count=0; text[count]!='\0'; ++count){
    fputc(text[count], f);
  }
  for(count=position; count<length; ++count){
    fputc(current[count], f);
  }
  fclose(f);

  return 0;
}

void removeAllText(char* filepath){
	FILE *f;
	f =  fopen(filepath,"w");
	fputs("", f);
	fclose(f);
}

void readPages(char* filepath, int pages){
  FILE *f;
  char c;
  int count = 0;
  f = fopen(filepath, "r");

  while((c = fgetc(f)) != EOF) {
    printf("%c", c);
    if(c == '\n'){
      count++;
      if (count == pages){
        getchar();
        count = 0;
      }
    }
  }
  fclose(f);
}

void fimanuCLI()
{
  // do not touch
  // I will implement that
}

int main() {

  fimanuCLI();

  return 0;
}
