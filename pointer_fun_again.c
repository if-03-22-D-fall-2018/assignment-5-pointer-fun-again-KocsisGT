#include <stdio.h>
#include <string.h>

struct PlayStruct
{
  int int_value;
  double double_value;
  char a_string[64];
};

void print_struct(struct PlayStruct ps, struct PlayStruct *pps);
void change_struct(struct PlayStruct ps, struct PlayStruct *pps); //It's simple, the value where the pointer is well... pointing gets changed
void print_string(char string_to_print[]);
void change_string(char string1[], char *p_string);

int main(int argc, char const *argv[])
{
  struct PlayStruct play_struct = {42, 2.5, "Crazy!"};
  struct PlayStruct *play_struct_pointer = &play_struct;
  char another_string[16] = {"Stylish"};
  char *another_string_pointer = another_string;
  print_struct(play_struct,play_struct_pointer);
  change_struct(play_struct,play_struct_pointer);
  print_struct(play_struct,play_struct_pointer);
  print_string(play_struct.a_string);
  change_string(play_struct.a_string, another_string_pointer);
  print_string(play_struct.a_string);
  print_string(another_string);
  return 0;
}

void print_struct(struct PlayStruct ps, struct PlayStruct *pps)
{
  printf("Values of struct ps: %d, %.3lf, %s\n",ps.int_value,ps.double_value, ps.a_string);
  printf("Values of struct pps: %d, %.3lf, %s\n",pps->int_value, pps->double_value, pps->a_string);
}

void change_struct(struct PlayStruct ps, struct PlayStruct *pps)
{
  ps.int_value = 21;
  ps.double_value = 1.25;
  strcpy(ps.a_string, "David Bowie - Changes");
  pps->int_value = 84;
  pps->double_value = 5;
  strcpy(pps->a_string, "Judas Priest - Victim of Changes");
}

void print_string(char string_to_print[]){
  printf("print_string: %s\n", string_to_print);
}

void change_string(char string1[], char *p_string){
  string1[2] = 0;
  p_string[1] = 0;
}
