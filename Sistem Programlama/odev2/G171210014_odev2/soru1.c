  #include <stdio.h>
  #include <malloc.h>    
  #include <unistd.h>
  #include <alloca.h>     

  extern void stack(void);    

              
  int veri = 200;     

  int  main(int argc, char **argv) 
  {
      char *ptr, *h;

      printf("\tData bölümü:  başlangıç=  %p, \t boyut= %lu Byte\n", &veri, sizeof(veri));
    
      stack();
     

      h = sbrk((ptrdiff_t) 32);   
      
      printf("\tYığıt bölümü: başlangıç=  %p, \t boyut= %lu Byte\n", h, sizeof(h));
  }

  void stack(void)
  {
      static int level = 0;       
      auto int yigin;        
      printf("\tYığın bölümü: başlangıç=  %p, \t boyut= %lu Byte\n", &yigin, sizeof(yigin));  
  }
  

