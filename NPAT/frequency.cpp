void mostFreq3(int *a, int n, int b[3]) {

// Write your code here
// hint: sort a, find biggest 3 blocks
  typedef struct freq {
  	int num;
    int frq;
  }freq;
  
  int i,j;
  
  int c = 0;
  
  for (i = 0; i < n; i++) {
  	// no of distinct elements
    int x = a[i];
    int flag = 0;
    for (j = i - 1; j >= 0; j--) {
    	// if x already occured, ignore
      if (x == a[j]) {
      	flag = 1;
        break;
      }
    }
    
    if (flag == 0) {
    	c++;
    }
  }
  
  freq nos[c];
  int k = 0;
  
  for (i = 0; i < n; i++) {
    int x = a[i];
    int freq_x = 1;
    // calc freq of x
    for (j = i + 1; j < n; j++) {
      if (a[j] == a[i]) {
      	freq_x++;
      }
    }
    int flag = 0;
    for (j = i - 1; j >= 0; j--) {
      if (a[j] == a[i]) {
      	flag = 1;
        break;
      }
    }
    
    if (flag == 0) {
    	nos[k].num = x;
    	nos[k].frq = freq_x;
      	k++;
    }
  }
  
  for (i = 0; i < c - 1; i++) {
    for (j = 0; j < c - i - 1; j++) {
      if ( nos[j].frq < nos[j+1].frq ) {
      	freq temp;
        
        temp.num = nos[j+1].num;
        temp.frq = nos[j+1].frq;
        
        nos[j+1].num = nos[j].num;
        nos[j+1].frq = nos[j].frq;
        
        nos[j].num = temp.num;
        nos[j].frq = temp.frq;
      }
    }
  }
  
  printf("c = %d\n", c);
  
  b[0] = nos[0].num;
  b[1] = nos[1].num;
  b[2] = nos[2].num;
  
  /*
  for (i = 0; i < c; i++) {
  	printf("%d = %d\n", nos[i].num, nos[i].frq);
  }
  */
}
