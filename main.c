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

void appendPosition(char* filepath, char* text, int position){
	FILE *f;
	f = fopen(filepath, "r");

  fseek(f, 0, SEEK_END);
	size_t length = ftell(f);
  fseek(f, 0, SEEK_SET);

  char current[length];
  char c;
  int count = 0;

  while((c = fgetc(f)) != EOF) {
    current[count] = c;
    count++;
  }
	fclose(f);

  f = fopen(filepath, "w");
  //write until position
  //write text
  //write from position
  fclose(f);
}

void removeAllText(char* filepath){
	FILE *f;
	f =  fopen(filepath,"w");
	fputs("", f);
	fclose(f);
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
