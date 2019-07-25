#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stc{
   char ottx;
   struct stc *nxt;
};



int pop(struct stc** TopRef);
void push(struct stc** TopRef, int Nottx);

int match(char ch1, char ch2)
                {
                       if (ch1 == '(' && ch2 == ')')
                         return 1;
                         else if (ch1 == '[' && ch2 == ']')
                         return 1;
                       else if (ch1 == '{' && ch2 == '}')
                         return 1;

                       else
                         return 0;
                }

int Pokk(char chk[])
{
   int i = 0;
   struct stc *str = NULL;
   while (chk[i])
                {
                    
                    
                    
                    
                      if (chk[i] == '{' || chk[i] == '(' || chk[i] == '[')
                        push(&str, chk[i]);
                      if (chk[i] == '}' || chk[i] == ')' || chk[i] == ']')
                                                                        {
                                                             if (str == NULL)
                                                               return 0;
                                                             else if ( !match(pop(&str), chk[i]) )
                                                               return 0;
                                                                            }
                      i++;
                    }

      if ( str == NULL)
     return 1;
   else
     return 0;
}

int main()
{

  char chk[100] = "if (x[i] > x[j]) { return;}";
  fgets (chk, 100, stdin);
  if (Pokk(chk))
    printf("\n\  input   ok!\n\n");
  else
    printf("\n\nString are not Valid!\n\n");
  return 0;
}

void push(struct stc** TopRef, int Nottx)
{
  struct stc* nfloz =
            (struct stc*) malloc(sizeof(struct stc));

  if (nfloz == NULL)
  {
     printf("error :Stack is Overflow,be careful next time!!! n");
     getchar();
     exit(0);
  }

  nfloz->ottx  = Nottx;

  nfloz->nxt = (*TopRef);
  (*TopRef)    = nfloz;
}
                                    int pop(struct stc** TopRef)
                                    {
                                      char out;
                                      struct stc *top;
                                         top = *TopRef;
                                         out = top->ottx;
                                         *TopRef = top->nxt;
                                         free(top);
                                         return out;
                                    }
