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
  // open with append mode
}

void appendPosition(char* filepath, char* text){
  // read all then write until position then write text
  // then contuni to write readed text
}

void removeAllText(char* filepath){
  // write empty char like ''
}

void readPages(char* filepath, int pages){
  // easy one :D
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
