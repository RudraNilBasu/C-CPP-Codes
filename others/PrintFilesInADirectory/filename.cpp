#include <dirent.h>
#include<stdio.h>

int main() {
DIR *dpdf;
struct dirent *epdf;

dpdf = opendir("./");
if (dpdf != NULL){
   while (epdf = readdir(dpdf)){
      printf("Filename: %s\n",epdf->d_name);
      // std::cout << epdf->d_name << std::endl;
   }
}
}
