/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:16:28 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/24 15:16:39 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>

#include <limits.h>
void ft_putstrit(char *mas)
{ 
   int i;
   i = 0;
   while (mas[i])
   {
      write(1, &mas[i], 1);
      i++;
   }
}

void ft_putstriter(unsigned int i, char *mas)
{
   write(1, &mas[i], 1);
   write(1, "\n", 1);
}

char ft_putstrmap(char c)
{
   c = '$';
   return (c);
}

char ft_putstrmapi(unsigned int i, char c)
{
   c = 'b';
   if ((i % 2) != 0)
      return('+');
   else
      return (c);
}


void ft_putstrlist(t_list *list)
{
   while (list)
   {
      ft_putstr(list->content);
      ft_putnbr(list->content_size);
      list = list->next;
   }
}

void ft_dellinks(void *mas, size_t x)
{
  int   i;
  char *mas1;

  mas1 = (char *)mas;
  i = 0;
   while (mas1[i] != '\0')
   {
      ft_putchar(mas1[i]);
      i++;
  }  
      ft_putnbr(x);
      //printf("\n");
     // printf("%s %p\n", mas, mas);
}

void makeputstr(t_list *list)
{
     while (list)
   {
      ft_putstr(list->content);
      ft_putnbr(list->content_size);
      list = list->next;
   }
}

t_list  **dmlist(t_list **head,void const *content, size_t content_size)
{
  t_list  *ret;
  ret = (t_list *)malloc(sizeof(t_list));
  ret->content = (void *)malloc(content_size);
  ft_memcpy(ret->content, content, content_size);
  ret->content_size = content_size;

  ret->next = (*head);
  (*head) = ret;
  return (head);
}

void parselist(t_list *elem)
{
  while (elem != NULL)
  {
    printf("parselist\n");
    elem = elem->next;
  }
}


t_list *parsemap(t_list *elem)
{
  t_list *mas;
  //printf("%s\n", (char *)elem->content);
  mas = (t_list *)malloc(sizeof(t_list));
  if (!mas)
    return (NULL);
  if ((mas->content = (void *)malloc(elem->content_size)) == NULL)
    return (NULL);
  ft_memcpy(mas->content, elem->content, elem->content_size);
  mas->content_size = elem->content_size;
    
  return (mas);
}





int   main(int argc, char **argv)
{
/////////////////////////////////////////////////////                            !!! 1
      printf("\n\n");
      printf("ft_memset                          (1)\n");
  int   i;
  char str[] = "Blackbird";
  int  str1[] = {0, 1, 2, 3, 4};                          //memset  $$$$$$$rd
                                                            //MYmemset $$$$$$$rd
  printf("memset  %s\n", memset(str,'$',7));
  printf("MYmemset %s\n", ft_memset(str,'$',7));

/////////////////////////////////////////////////////                            !!! 2
      printf("\n\n");
      printf("ft_bzero                          (2)\n");
      char mas40[] = "Blackbird";
      char mas41[] = "Blackbird";

      bzero(mas40,7);
      i = 0;
      printf("bzero ");
      while (mas40[i] == 0)
      {
         printf("%d", mas40[i]);
         i++;
      }
      printf("\n");

      ft_bzero(mas41,7);                                    //0000000
      i = 0;
      printf("MYft_bzero ");                                //0000000
      while (mas41[i] == 0)
      {
         printf("%d", mas41[i]);
         i++;
      }

/////////////////////////////////////////////////////                            !!! 3
      printf("\n\n");
      printf("ft_memcpy                          (3)\n");
      char bz[] = "Blackbird";
  char ll[20];
   char ll2[20];


  memcpy(ll, bz, strlen(bz) + 1);                         //memcpy_char Blackbird
  ft_memcpy(ll2, bz, strlen(bz) + 1);                     //MYmemcpy_char Blackbird
   
   printf("memcpy_char %s\n", ll);
   printf("MYmemcpy_char %s\n", ll2);


 /////////////////////////////////////////////////////                            !!! 4
      printf("\n\n"); 
   printf("ft_memccpy                          (4)\n");
   char lz[20];
   char lz2[20]; 
  memccpy(lz, bz, 99, 3);  //99 == 'c'                             //memccpy_char Bla
  ft_memccpy(lz2, bz, 99, 3);// == numbers of bytes cop
  printf("memccpy_char %s\n", lz);                        //MYmemccpy_char Bla
   printf("MYmemccpy_char %s\n", lz2);


      char  src13[] = "test basic du memccpy !";
      char  buff2 [22];

      memset(buff2, 0, sizeof(buff2));
      char  *r1 = memccpy(buff2, src13, 'm', 22);
      char  *r2 = ft_memccpy(buff2, src13, 'm', 22);
    printf("memccpy_char %s\n", r1);                       
    printf("MYmemccpy_char %s\n", r2);


/////////////////////////////////////////////////////                            !!! 5
      printf("\n\n");
      printf("ft_memmove                          (5)\n");
   char oldbv[] = "Black bird .....";
  char oldbv2[] = "Black bird .....";
  const char bv2[] = "ANGRY";
  
   memmove(oldbv+11, oldbv+6, 5);                        //Black bird bird
  ft_memmove(oldbv2+11, oldbv+6, 5);                    //Black bird bird
   printf("memmove_char %s\n", oldbv);
  //printf("MYmemmove_char %s\n", oldbv2);


      /*int   size = 128 * 1024 * 1024;
      char  *dst14 = (char *)malloc(sizeof(char) * size);
      char  *data = (char *)malloc(sizeof(char) * size);

      memset(data, 'A', size);
         printf("memmove_char %s\n", ft_memmove(dst14, data, size));*/

    /*char bv3[] =  "the cake is a lie !\0I'm hidden lol\r\n";
    char bv4[] =  "the cake is a lie !\0I'm hidden lol\r\n";
    int   size1 = strlen(bv3);
    memmove(bv3, bv3, size1);
    ft_memmove(bv4, bv4, size1);
    printf("memmove_char %s\n", bv3);
    printf("MYmemmove_char %s\n", bv4);*/

      /*char  dst14[0xF0];
      char  dst15[0xF0];
      char  *data = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
      int   size2 = 0xF0 - 0xF;

      memset(dst14, 'A', sizeof(dst14));
      memset(dst15, 'A', sizeof(dst15));
      printf("%d\n", size2);
      printf("dst14 %lu\n", sizeof(dst14));

      memcpy(dst14, data, strlen(data));
      memcpy(dst15, data, strlen(data));

  memmove(dst14 + 3, dst14, size2);*/
    
   /* ft_memmove(dst15 + 3, dst15, size2);
   printf("memmove_char %s\n", dst14);
      printf("%lu\n", sizeof(dst14));
      printf("\n");
    printf("MYmemmove_char %s\n", dst15);*/


/////////////////////////////////////////////////////                            !!! 6
      printf("\n\n");
      printf("ft_memchr                          (6)\n");
   char st[] = "Blackbird";
   char ch = 'c';   
   char *ret;
   char *ret3;
      ret3 = memchr(st, ch, strlen(st));
    ret = ft_memchr(st, ch, strlen(st));
      printf("memchr %s\n", ret3);                          //ckbird
    printf("MYmemchr %s\n",  ret);                         //ckbird

/////////////////////////////////////////////////////                            !!! 7
      printf("\n\n");
      printf("ft_memcmp                          (7)\n");
    char str3[7];
    char str4[7];     
    int ret1;
    int ret2;
    memcpy(str3, "abcdef", 6);
   memcpy(str4, "ABCDEF", 6);
    ret1 = memcmp(str3, str4, 5);
    ret2 = ft_memcmp(str3, str4, 5);
      printf("memcmp %d\n",ret1);
    if(ret1 > 0) {
      //printf("%d\n",ret1);
      printf("MYmemcmp %d\n",ret2);                         //32
    } else if(ret1 < 0) {                                 //32
      //printf("%d\n",ret1);
      printf("MYmemcmp %d\n",ret2);
    } else {
      //printf("%d\n",ret1);
      printf("MYmemcmp %d\n",ret2);
    }

/////////////////////////////////////////////////////                            !!! 8
      printf("\n\n");
      printf("ft_strlen                          (8)\n");
    char mso[] = "Blackbird";
    printf("strlen %lu\n", strlen(mso));                    //9
    printf("MYstrlen %zu\n", ft_strlen(mso));               //9

/////////////////////////////////////////////////////                            !!! 9
      printf("\n\n");
      printf("ft_strdup                          (9)\n");
      char mas42[] = "Blackbird";
      char mas43[] = "Blackbird";
      char *mas44; 
      char *mas45;
      mas44 = strdup(mas42);      
      mas45  = ft_strdup(mas42);
      i = 0;
      if (mas44 != NULL)
      {
         printf("strdup ");
         while (mas44[i])
         {
            printf("%c", mas44[i]);
            i++;
         }
      }
      printf("\n");                                            //Blackbird
      i = 0;
      if (mas45 != NULL)                                       //Blackbird
      {
         printf("MYstrdup ");
         while (mas45[i])
         {
            printf("%c", mas45[i]);
            i++;
         }
      } 

 /////////////////////////////////////////////////////                            !!! 10    
      printf("\n\n");
      printf("ft_strcpy                          (10)\n"); 

    char mso1[190];
      char mso30[190];
      printf("strcpy %s\n", strcpy(mso1, mso));          //Blackbird
    printf("MYstrcpy %s\n", ft_strcpy(mso30, mso));   //Blackbird

 /////////////////////////////////////////////////////                            !!! 11    
      printf("\n\n");
      printf("ft_strncpy                          (11)\n"); 
      char mso31[20];
      char mso32[25];

      /*char  *src12 = "--> nyancat <--\n\r";
      char  dst12[30];
      size_t  max = 12;*/
      char  *src12 = "--> nyancat <--\n\r";
      char  dst12[30];
      char  dst13[30];
      size_t  max = 12;

            memset(dst12, 'B', sizeof(dst12));
      memset(dst13, 'B', sizeof(dst13));

      printf("strncpy %s\n", strncpy(dst12, src12, max) );
       printf("Mystrncpy %s\n", ft_strncpy(dst13, src12, max) );
       printf("%d\n", memcmp(dst12, dst13, 29));

      strncpy(mso31, mso, 20);
      i = 0;
      printf("strncpy ");
      while (mso31[i])
      {
         printf("%c", mso31[i]);             //abc\0\0\0'
         i++;
      }
      i = 0;
      while (mso31[i] == '\0')
      {
         printf("%c", mso31[i]);                            //Blackbird
         i++;                                               //Blackbird
      }
      printf("\n");
    printf("MYstrncpy %s\n", ft_strncpy(mso32, mso, 20));

 /////////////////////////////////////////////////////                            !!! 12    
      printf("\n\n");
      printf("ft_strcat                          (12)\n"); 
    char mso2[] = "Blackbird";
    char mso3[40] = "The best ";
      char mso33 [] = "Blackbird";
      char mso34[40] = "The best ";      
    printf("strcat %s\n", strcat(mso3, mso2));           //The best Blackbird
    printf("MYstrcat %s\n", ft_strcat(mso34, mso33));    //The best Blackbird


 /////////////////////////////////////////////////////                            !!! 13  
       printf("\n\n");
      printf("ft_strncat                          (13)\n");  
      char mso4[] = "Blackbird";
    char mso5[40] = "The best ";
      char mso38[] = "Blackbird";
     char mso37[40] = "The best ";
    printf("strncat %s\n", strncat(mso5, mso4, 5));      //The best Black
    printf("MYstrncat %s\n", ft_strncat(mso37, mso38, 5));    //The best Black

 /////////////////////////////////////////////////////                            !!! 14 
      /*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless size <= strlen(dst)).
 * Returns strlen(src) + MIN(size, strlen(initial dst)).
 * If retval >= size, truncation occurred.
 */
       printf("\n\n");
      printf("ft_strlcat                          (14)\n");  
    char mso6[] = "BlackbirdOnTree";//16
    char mso7[5] = "Best";
       printf("strlcat %lu\n", strlcat(mso7, mso6, 1)); 
    printf("MYstrlcat %zu\n", ft_strlcat(mso7, mso6, 1));
       printf("strlcat %lu\n", strlcat(mso7, mso6, 0)); 
      printf("MYstrlcat %zu\n", ft_strlcat(mso7, mso6, 0));
      printf("strlcat %zu\n", strlcat(mso7, mso6, 5));
      printf("MYstrlcat %zu\n", ft_strlcat(mso7, mso6, 5));

 /////////////////////////////////////////////////////                            !!! 15
       printf("\n\n");
      printf("ft_strchr                          (15)\n");


    char mso8[] = "Blackbird";
    int fn = 107;//k    
    printf("strchr %s\n", strchr(mso8, fn)); 
    printf("MYstrchr %s\n", ft_strchr(mso8, fn));
      int fn6 = 122;//z     
      printf("strchr %s\n", strchr(mso8, fn6)); 
      printf("MYstrchr %s\n", ft_strchr(mso8, fn6));

      char  *src14 = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";

           printf("strchr %s\n", strchr(src14, '\0')); 
      printf("MYstrchr %s\n", ft_strchr(src14, '\0'));
      printf("strchr %lu\n",  sizeof(strchr(src14, '\0'))); 
      printf("MYstrchr %lu\n", sizeof(strchr(src14, '\0')));

 /////////////////////////////////////////////////////                            !!! 16
       printf("\n\n");
      printf("ft_strrchr                          (16)\n");
    char mso9[] = "Blackbird";
    int fn1 = 98;     
    printf("strrchr %s\n", strrchr(mso9, fn1)); //bird
    printf("MYstrrchr %s\n", ft_strrchr(mso9, fn1));
      int fn7 = 122;  //z   
      printf("strrchr %s\n", strrchr(mso9, fn7));
      printf("MYstrrchr %s\n", ft_strrchr(mso9, fn7));   

      char  *src15 = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
      printf("strrchr %s\n", strrchr(src15, '\0'));
      printf("Mystrrchr %s\n", ft_strrchr(src15, '\0'));


 /////////////////////////////////////////////////////                            !!! 17
       printf("\n\n");
      printf("ft_strstr                          (17)\n");
    //char mso10[] = "Blackbird";

      char  *s11 = "MZIRIBMZIRIBMZP";
      char  *s21 = "MZIRIBMZP";

      printf("strstr %s\n", strstr(s11, s21)); 
      printf("Mystrstr %s\n", ft_strstr(s11, s21)); 

       char  *s13 = "ergr";
      char  *s23 = "";
      printf("strstr %s\n", strstr(s13, s23)); 
      printf("Mystrstr %s\n", ft_strstr(s13, s23));

      char  *s12 = "";
      char  *s22 = "";
      printf("strstr %s\n", strstr(s12, s22)); 
      printf("Mystrstr %s\n", ft_strstr(s12, s22));

      char  *s14 = "";
      char  *s24 = "ergr";
      printf("strstr %s\n", strstr(s14, s24)); 
      printf("Mystrstr %s\n", ft_strstr(s14, s24));

      //printf("strstr %s\n", strstr("yep", NULL)); 
      //printf("Mystrstr %s\n", ft_strstr("yep", NULL));

      //printf("strstr %s\n", strstr(NULL, "yep"));
    //printf("Mystrstr %s\n", ft_strstr(NULL, "yep"));

    /*printf("strstr %s\n", strstr(mso10, fn2)); //bird
      printf("MYstrstr %s\n", ft_strstr(mso10, fn2));
      char fn8[] = "ls";     
      printf("strstr %s\n", ft_strstr(mso9, fn8));
      printf("MYstrstr %s\n", ft_strstr(mso9, fn8));*/   

 /////////////////////////////////////////////////////                            !!! 18
       printf("\n\n");
      printf("ft_strnstr                          (18)\n");
      char mso11[] = "Bla\0ckbird";
      char fn3[] = "r";
      printf("strnstr %s\n", strnstr(mso11, fn3, 8));
      printf("MYstrnstr %s\n", ft_strnstr(mso11, fn3, 8)); 
      printf("strnstr %s\n", strnstr("Blackbird", fn3, 8));       //rd
      printf("MYstrnstr %s\n", ft_strnstr("Blackbird", fn3, 8));  //rd 

      char  *s25 = "FF";
      char  *s26 = "see FF your FF return FF now FF";
      size_t  max25 = strlen(s26);//31

     printf("strnstr %s\n", strnstr(s25, s26, max25));       
      printf("GMYstrnstr %s\n", ft_strnstr(s25, s26, max25)); 
     // printf("strnstr %s\n", strnstr(NULL, s26, 4));       
     // printf("MYstrnstr %s\n", ft_strnstr(s25, NULL, 4)); 
    printf("strnstr %s\n", strnstr(s25, "", 4));       
    printf("MYstrnstr %s\n", ft_strnstr(s25, "", 4));


 /////////////////////////////////////////////////////                            !!! 19
       printf("\n\n");
      printf("ft_strcmp                          (19)\n");
      char mso12[] = "Blackbird";
      char fn4[] = "Blackbird";
      char mso15[] = "Blacakbird";
      char fn9[] = "Blackbird";
      char  *s27 = "\0";
      char  *s28 = "\200";
      char  *s29 = "\x12\xff\x65\x12\xbd\xde\xad";
      char  *s30 = "\x12\x02";
      printf("strcmp %d\n", strcmp(s27, s28));
      printf("MYstrcmp %d\n", ft_strcmp(s27, s28));

      printf("strcmp %d\n", strcmp(s29, s30));
      printf("MYstrcmp %d\n", ft_strcmp(s29, s30));

      printf("strcmp %d\n", strcmp(mso12, fn4));
      printf("MYstrcmp %d\n", ft_strcmp(mso12, fn4));
      printf("strcmp %d\n", strcmp(mso15, fn9));
      printf("MYstrcmp %d\n", ft_strcmp(mso15, fn9));      

 /////////////////////////////////////////////////////                            !!! 20
       printf("\n\n");
      printf("ft_strncmp                          (20)\n");
      char mso13[] = "Blackbird";
      char fn5[] = "Blackbirda";
      printf("strncmp %d\n", strncmp(mso13, fn5, 10));
      printf("MYstrncmp %d\n", ft_strncmp(mso13, fn5, 10));
      printf("strncmp %d\n", strncmp(mso13, fn5, 8));
      printf("MYstrncmp %d\n", ft_strncmp(mso13, fn5, 8));


 /////////////////////////////////////////////////////                            !!! 21
       printf("\n\n");
      printf("ft_atoi                          (21)\n");
      char mso14[] = "     +-1234Blackbird";
      char at[] = "     -1234Bl5ackbird";
      char at1[] = "  \t \n  +1234Bl5ackbird";
      char  *mso16 = "\e06050";

           printf("atoi %d\n", atoi(mso16));
      printf("MYatoi %d\n", ft_atoi(mso16));
      printf("atoi %d\n", atoi("12345678900000000"));
      printf("MYatoi %d\n", ft_atoi("12345678900000000")); 
      printf("atoi %d\n", atoi("99999999999999999999999999"));
      printf("overMYatoi %d\n", ft_atoi("99999999999999999999999999"));
            printf("atoi %d\n", atoi("-99999999999999999999999999"));
      printf("minoverMYatoi %d\n", ft_atoi("-99999999999999999999999999"));      
      printf("atoi %d\n", atoi(mso14));
      printf("atoi %d\n", atoi(at));
      printf("atoi %d\n", atoi(at1));
      printf("MYatoi %d\n", ft_atoi(mso14));
      printf("MYatoi %d\n", ft_atoi(at));
       printf("MYatoi %d\n", ft_atoi(at1));

       //char n1[40];
 /////////////////////////////////////////////////////                            !!! 22
       printf("\n\n");
      printf("isalpha                          (22)\n");
      printf("isalpha %d\n", isalpha('d'));
      printf("isalpha %d\n", isalpha('A'));
      printf("isalpha %d\n", isalpha('\t')); 
      printf("MYft_isalpha %d\n", ft_isalpha('d'));
      printf("MYft_isalpha %d\n", ft_isalpha('A'));
      printf("MYft_isalpha %d\n", ft_isalpha('\t'));

  /////////////////////////////////////////////////////                            !!! 23
       printf("\n\n");
      printf("isdigit                          (23)\n");
      printf("isdigit %d\n", isdigit('d'));
      printf("isdigit %d\n", isdigit('9')); 
      printf("MYft_isdigit %d\n", ft_isdigit('d'));
      printf("MYft_isdigit %d\n", ft_isdigit('9'));

  /////////////////////////////////////////////////////                            !!! 24
       printf("\n\n");
      printf("isalnum                         (24)\n");
      printf("isalnum %d\n", isalnum('d'));
      printf("isalnum %d\n", isalnum('9'));
      printf("isalnum %d\n", isalnum('\t')); 
      printf("MYft_isalnum %d\n", ft_isalnum('d'));
      printf("MYft_isalnum %d\n", ft_isalnum('9'));
      printf("MYft_isalnum %d\n", ft_isalnum('\t'));

  /////////////////////////////////////////////////////                            !!! 25
       printf("\n\n");
       printf("isascii                         (25)\n");
      printf("isascii %d\n", isascii(0));
      printf("isascii %d\n", isascii(127));
      printf("isascii %d\n", isascii(128)); 
      printf("MYft_isascii %d\n", ft_isascii(0));
      printf("MYft_isascii %d\n", ft_isascii(127));
      printf("MYft_isascii %d\n", ft_isascii(128));

  /////////////////////////////////////////////////////                            !!! 26
       printf("\n\n");
       printf("isprint                         (26)\n");
      printf("isprint %d\n", isprint(31));
      printf("isprint %d\n", isprint(32));
      printf("isprint %d\n", isprint(127)); 
      printf("MYft_isprint %d\n", ft_isprint(31));
      printf("MYft_isprint %d\n", ft_isprint(32));
      printf("MYft_isprint %d\n", ft_isprint(127));

  /////////////////////////////////////////////////////                            !!! 27
       printf("\n\n");
       printf("toupper                         (27)\n");
      printf("toupper %c\n", toupper(33));
      printf("toupper %c\n", toupper(98));
      printf("toupper %c\n", toupper(90));
      printf("MYft_toupper %c\n", ft_toupper(33));
      printf("MYft_toupper %c\n", ft_toupper(98)); 
      printf("MYft_toupper %c\n", ft_toupper(90));

  /////////////////////////////////////////////////////                            !!! 28
       printf("\n\n");
       printf("tolower                         (28)\n");
      printf("tolower %c\n", tolower(33));
      printf("tolower %c\n", tolower(89));
      printf("tolower %c\n", tolower(122));
      printf("MYft_tolower %c\n", ft_tolower(33));
      printf("MYft_tolower %c\n", ft_tolower(89));
      printf("MYft_tolower %c\n", ft_tolower(122));


                                                                                             //PART 2



  /////////////////////////////////////////////////////                            !!! 29
       printf("\n\n");
       printf("memalloc                         (29)\n");
      char *m = ft_memalloc(5);
      i = 0;
      if (m != NULL)
      {
         while (*m == 0)
         {
            printf("%d", *m);                               //00000
            m++;
         }
      }

   /////////////////////////////////////////////////////                            !!! 30
       printf("\n\n");
       printf("memdel                         (30)\n");
       char *a;
       
       a = (char *)malloc(sizeof(*a) * 4);
       strcpy(a, "tut");
       printf("%s, %p\n",a, a);

       /*void **z = (void *)&a;
       if (*z)
       {
         free(*z);
         *z = NULL;
       }*/
       ft_memdel((void *)&a);
       printf("%s, %p\n",a, a);


   /////////////////////////////////////////////////////                            !!! 31
       printf("\n\n");
       printf("strnew                         (31)\n");  
       char *op = ft_strnew(5);
       
       i = 0;
       if (op != NULL)
       {
         while (op[i] == 0 && i < 5)
         {
            op[i] = 'e';
            i++;
         }
         i = 0;
         while (*op && i < 5)
         {
            printf("%c", *op);
            op++;
            i++;
         }
       }

     /////////////////////////////////////////////////////                            !!! 32 
     printf("\n\n");  
     printf("strdel                         (32)\n");
      char *st1;
       
       st1 = (char *)malloc(sizeof(*st1) * 6);
       strcpy(st1, "Black");
       printf("%s, %p\n",st1, st1);

       ft_strdel(&st1);
       printf("%s, %p\n",st1, st1);


    /////////////////////////////////////////////////////                            !!! 33
     printf("\n\n");
      printf("strclr                         (33)\n");
      char mas8[] = "Blackbird";

      ft_strclr(mas8);
      //Sets every character of the string to the value ’\0’
       i = 0;
          while (mas8[i] == 0)
         {
            printf("%d", mas8[i]);                          //0000000000
            i++;
         }
      
 /////////////////////////////////////////////////////////////                            !!! 34     ??????????????????
     printf("\n\n");
      char mas11[] = "BlacK";
      printf("ft_striter                         (34)\n");
     ft_striter(mas11, &ft_putstrit); //void ft_putstr(char *c);



 ///////////////////////////////////////////////////////////                            !!! 35      ???????????????????
     printf("\n\n");
      char op3[] = "BlacK";
     printf("ft_striteri                          (35)\n");
   ft_striteri(op3, &ft_putstriter);                          //BaKBa



/////////////////////////////////////////////////////                                   !!! 36
      printf("\n\n");
      printf("ft_strmap                      (36)\n");
      char mas12[] = "Blackbird";
      printf("MYft_strmap\n");
      char *mas13;
      mas13 = ft_strmap(mas12, &ft_putstrmap);
      i = 0;
      if (mas13 != NULL)
      {
         while (mas13[i])
         {
            write(1, &mas13[i], 1);
            i++;
         }         
      }
      
      

//////////////////////////////////////////////////////                                  !!! 37
      printf("\n\n");
      printf("ft_strmapi                       (37)\n");
      char mas14[] = "Blackbird";
      char *mas15;

      mas15 = ft_strmapi(mas14, &ft_putstrmapi);
      i = 0;
      if (mas15 != NULL)
      {
         while (mas15[i])
         {
            write(1, &mas15[i], 1);                ////    b+b+b+b+b
            i++;
         }
      } 

///////////////////////////////////////////////////////                            !!! 38  
      printf("\n\n");
      printf("ft_strequ                         (38)\n");
      char mas16[] = "Blackbird";
      char mas17[] = "Blackbird";
      char mas18[] = "Blackbird";
      char mas19[] = "Blackabird";      
      printf("%d\n", ft_strequ(mas16, mas17));                 //1
      printf("%d\n", ft_strequ(mas18, mas19));                 //0

/////////////////////////////////////////////////////                            !!! 39
      printf("\n\n");
      printf("ft_strnequ                         (39)\n");
      char mas20[] = "Blackbird";
      char mas21[] = "Blackbird";
      char mas22[] = "Blackbird";
      char mas23[] = "Blackabird";      
      printf("%d\n", ft_strnequ(mas20, mas21, 9));             //1
      printf("%d\n", ft_strnequ(mas20, mas21, 7));             //1
      printf("%d\n", ft_strnequ(mas22, mas23, 7));             //0


/////////////////////////////////////////////////////////////                            !!! 40
      printf("\n\n");
      printf("ft_strsub                           (40)\n");
      char mas24[] = "Blackbird";
      printf("%s\n", ft_strsub(mas24, 2, 5));                  //ackbi
      printf("%s\n", ft_strsub(mas24, 8, 9));                  // d
      printf("%s\n", ft_strsub(mas24, 3, 10));                 // ckbird
      printf("%s\n", ft_strsub(mas24, 6, 1));                  // null

       char  *mas33 = "i just want this part #############";  //t want this part ###
      printf("%s\n", ft_strsub(mas33, 5, 20));


/////////////////////////////////////////////////////                            !!! 41
      printf("\n\n");
      printf("ft_strjoin                           (41)\n");
      char mas25[] = "The best "; //9len
      char mas26[] = "Blackbird";  //9len 
      char *mas27;
      printf("%s\n", ft_strjoin(mas25, mas26));             //The best Blackbird
      //printf("%s\n", ft_strjoin(mas25, mas27));             //NULL

/////////////////////////////////////////////////////                            !!! 42
      printf("\n\n");
      printf("ft_strtrim                           (42)\n");
      char mas28[] = "Blackbird"; 
      char mas29[] = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
      char mas30[] = "Blackbird    \t    \n";
      char *mas31;
      mas31 = 0;
      printf("%s\n", ft_strtrim(mas28));                    //Blackbird
      printf("%s\n", ft_strtrim(mas29));                    //Blackbird
      printf("%s\n", ft_strtrim(mas30));                    //Blackbird
      printf("%s\n", ft_strtrim(mas31));                    //NULL
      printf("blank %s\n", ft_strtrim("  \t \t \n   \n\n\n\t"));
      printf("empty %s\n", ft_strtrim(""));
       //printf("%zu\n", ft_strlen("")); 
      // printf("%zu\n", ft_strlen("  \t \t \n   \n\n\n\t")); 

     // printf("%lu\n", strlen("Hello \t  Please\n Trim me !"));//26 length
      //printf("cmp %d\n", strcmp("", ""));
/////////////////////////////////////////////////////                            !!! 43
      printf("\n\n");
      printf("ft_strsplit                          (43)\n");
      char *obj3 = "split  ||this|for|me|||||!|";          
      char **obj4;
      obj4 = ft_strsplit(obj3, '|');

      i = 0;
      if (obj4 != NULL)
      {
         while (obj4[i])                                           
         {                                                          //hello
            printf("%s\n", obj4[i]);                               //fellow
            i++;                                                    //students
         }
      }
      printf("\n");
       //printf("%s\n", obj4[0]);
      printf("%s\n", ft_strsplit("BlacK", '*')[0]);               //Black
      printf("%s\n", ft_strsplit("***", '*')[0]);                 //null     
      printf("%s\n", ft_strsplit("***YO", '*')[0]);               //YO
      printf("%s\n", ft_strsplit("DJ**", '*')[0]);                //DJ
      printf("%s\n", ft_strsplit("____xDD", '_')[0]);             //xDD
      //printf("%s\n", ft_strsplit("^^^^^Whats' UP", '^')[0]);      //Whats' UP

/////////////////////////////////////////////////////                            !!! 44
      printf("\n\n");
      printf("ft_itoa                          (44)\n");
      printf("%s\n", ft_itoa(-2147483648));
      printf("%s\n", ft_itoa(-21474836));
      printf("%s\n", ft_itoa(2147483647));
      printf("%s\n", ft_itoa(52346));
      printf("%s\n", ft_itoa(0));
      printf("%s\n", ft_itoa(1));

/////////////////////////////////////////////////////                            !!! 45
      printf("\n\n");
      printf("ft_putchar                          (45)\n");
      ft_putchar('B');

/////////////////////////////////////////////////////                            !!! 46
      printf("\n\n");
      printf("ft_putstr                          (46)\n");
      ft_putstr("Blackbird");

/////////////////////////////////////////////////////                            !!! 47
      printf("\n\n");
      printf("ft_putendl                          (47)\n"); 
      ft_putendl("Blackbird");

/////////////////////////////////////////////////////                            !!! 48
      printf("\n\n");
      printf("ft_putnbr                          (48)\n");
       ft_putnbr(-2147483648);
       printf("\n");
      ft_putnbr(-21474836);
      printf("\n");
      ft_putnbr(2147483647);
      printf("\n");
      ft_putnbr(52346);
      printf("\n");
      ft_putnbr(0);
      printf("\n");
      ft_putnbr(1);             

/////////////////////////////////////////////////////                            !!! 49
      printf("\n\n");
      printf("ft_putchar_fd                          (49)\n");
      int fd;
      fd = open("test", O_WRONLY);
      ft_putchar_fd('Z', fd);      

/////////////////////////////////////////////////////                            !!! 50
      printf("\n\n");
      printf("ft_putstr_fd                          (50)\n");
      char op4[] = " The Best ";
      ft_putstr_fd(op4, fd);

/////////////////////////////////////////////////////                            !!! 51
      printf("\n\n");
      printf("ft_putendl_fd                          (51)\n");
      char op5[] = "Blackbird";
      ft_putendl_fd(op5, fd);

/////////////////////////////////////////////////////                            !!! 52
      printf("\n\n");
      printf("ft_putnbr_fd                          (52)\n");
      ft_putchar_fd('\n', fd); 
            ft_putnbr_fd(-2147483648, fd);
      ft_putchar_fd('\n', fd);
            ft_putnbr_fd(-21474836, fd);
      ft_putchar_fd('\n', fd);
             ft_putnbr_fd(2147483647, fd);
      ft_putchar_fd('\n', fd);
            ft_putnbr_fd(0, fd);
      ft_putchar_fd('\n', fd);
            ft_putnbr_fd(1, fd);   

                                                                                 //Bonus
/////////////////////////////////////////////////////                            !!! 53
      printf("\n\n");
      printf("ft_lstnew                          (53)\n");
      t_list   *list;
      list = NULL;
      list = ft_lstnew("Blackbird", 9);
      //list = ft_lstnew("Black", 5);
      //list = ft_lstnew(me, 6);
      ft_putstrlist(list);
     // printf("%s\n", list->content);

/////////////////////////////////////////////////////                            !!! 54
      printf("\n\n");
      printf("ft_lstdelone                         (54)\n");
      //ft_putstrlist(list);
      printf("%p\n", &list->content); //Adress
      ft_lstdelone(&list, &ft_dellinks);

      printf("\n!!!After errase!!!\n");
      printf("%p\n", &list->content);
      printf("%s\n", (char *)&list->content);

/////////////////////////////////////////////////////                            !!! 55
      printf("\n\n");
       printf("ft_lstdel                         (55)\n");
       list = ft_lstnew("Blackbirds", 10);
       ft_putstrlist(list);
       printf("%p\n", &list->content); //Adress
       ft_lstdel(&list, &ft_dellinks);

       printf("\n!!!After errase!!!\n");
      printf("%p\n", &list->content);
      printf("%s\n", (char *)&list->content);

/////////////////////////////////////////////////////                            !!! 56
      printf("\n\n");
       printf("ft_lstadd                         (56)\n");
       list = NULL;
      ft_lstadd(dmlist(&list, "cat", 4), ft_lstnew("Blackbird", 10));
       makeputstr(list);

/////////////////////////////////////////////////////                            !!! 57
      printf("\n\n");
       printf("ft_lstiter                         (57)\n");
       ft_lstiter(list, &parselist);

/////////////////////////////////////////////////////                            !!! 58
      printf("\n\n");
      printf("ft_lstmap                         (58)\n");
      t_list  *new;
      new = NULL;

      new = ft_lstmap(list, &parsemap);   
      makeputstr(new);    

  i = 0;
  return (0);
}
