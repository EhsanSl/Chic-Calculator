#include <stdio.h>
#include <math.h>
#include <ctype.h>
//Universal variables
static double arr[100]= {0};

static int ans_count = 0;

double v,w,x,y,z;


//Functions
double varCreation(char varname, double v, double w, double y, double x, double z);
double varCreation2(char varname, double v, double w, double y, double x, double z);
double options();
double append_array();
double get_pos(double e);


char opcheck(char op2);
char opcheck2(char op2);


//Main functions
void Rf();
void Mf();
void Vf();
double Uf(double a,char op);
double Bf(double a ,char op ,double c);
double Af(char selection2,double a , char op , double b);

int main(void)
{




  printf("Welcome to my Command-Line Calculator (CLC)\n");
  printf("Developer: Ehsan Salimi\n");
  printf("Version: 3\n");
  printf("Date: 10/19/2020\n");
  printf("-----------------------------------------------------------\n");
  

//##############################################################################
  
  
//#####################

  
  char selection,selection2;
  
  char varname,varname2;
  char op;
  double a,b,c,e=0;
//main menu exot hole
  int asa=0;

//##############################################################################
  
  while (asa<1){
   
    selection = options();
    
    switch (selection)
    {

    case 'B':
      printf("Please enter the first number\n");
      scanf("%lf", &a);
      printf("Please enter the operation \n");
      printf("( + , - , * , / , %% , P (for  power) , X (for maximum) , I (for minimum) ):\n"); // If you want to printf % symbol you should type %%
      getchar();                                                                                //  Add another call to getchar before this to eat the newline.
      op = getchar();
      op = opcheck(op);
      
      printf("Please enter the second number\n");
      scanf("%lf", &b);
      
      
      c = Bf(a,op,b);
      

      printf("\nThe result is:     %.2lf\n", c);
      puts("______________________________________");
      getchar();
      break;
    continue;

  //for this case we define a variable so it will take care of the fact that we just accept positive vaue for these kind of calculation and we set it equal to zero after every time so if they decide to use a mode twice or more there wont be any problem.
    case 'U':
      printf("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):\n");
      
      getchar();
      scanf("%c",&op);
      op = opcheck2(op);
      
      if (op == 's' || op =='S' || op =='l'|| op=='L' || op =='e'|| op == 'E'){
        printf("please enter a positive number or a variable\n");
        scanf("%lf", &a);
        a = get_pos(a);
      }

      else if( op == 'c' || op == 'C' || op == 'f' || op == 'F'){
        printf("please enter a number\n");
        scanf("%lf" , &a);
      }

      c = Uf(a,op);

      append_array(arr,c);
      printf("The result is:     %.2lf\n", c);
      puts("______________________________________");
      

      getchar();
      break;
    continue;

  //##################################################################
  //##################################################################
  //##################################################################
    
    case 'V': 
      Vf();

      getchar();    
      break;
    continue;
//########################################################################
//########################################################################
    
    case 'A':
      while(1){
           
        printf("Please select your option:\nB (Binary Operation),\nU (Unary operation),\nE (Exit and back to main menu)\n");
        scanf(" %c", &selection2);
        if (selection2== 'b' || selection2=='B'){
          // get the input from the user and check its validity
          printf("please enter a number or an assigned variable:\n");
          //checking if its a variable or a number
          if (scanf("%lf",&a)){
          }
          else {
            scanf("%c", &varname);
            a = varCreation(varname, v,w,x,y,z);
            }


          printf("Please enter the operation ( + , -, * / , %% , P (for power) , X (for maximum) , I (for minimum) ):\n");         
          //scanf(" %c", &op);
          getchar();                                                         
          op = getchar();
          op = opcheck(op);
          
          
          printf("Please enter the second number or an assigned variable:\n");
          //checking if its a variable or a number
          
          while(1){
            if (scanf("%lf",&b))
            {  }
            else 
            {
              scanf("%c", &varname);              
              b = varCreation(varname, v,w,x,y,z);
              if ( b == 0 )
                puts("please enter a non-zero number:");
                scanf("%c",&varname);
                continue;
            }
            break;
          }
          c = Af(selection2,a , op , b);
          

          printf("\nThe result is:     %.2lf\n", c);
          puts("______________________________________");
        }
  //Unary option in A
        else if (selection2=='u'|| selection2=='U')
        {
          printf("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):\n");
          double b = 0;
      
          getchar();
          scanf("%c",&op);
          op = opcheck2(op);
          
          if (op == 's' || op =='S' || op =='l'|| op=='L' || op =='e'|| op == 'E'){
            printf("please enter a positive number or a variable\n");
            if (scanf("%lf",&a)){
              a = get_pos(a);
            }
            else {
              scanf("%c", &varname);
              a = varCreation(varname, v,w,x,y,z);
              a = get_pos(a);
            }
            
          }

          else if( op == 'c' || op == 'C' || op == 'f' || op == 'F'){
            printf("please enter a number or a variable\n");
            if (scanf("%lf",&a)){
            }
            else {
              scanf("%c", &varname);
              a = varCreation(varname, v,w,x,y,z);
            }
            
          }

          c = Af(selection2 , a, op ,b);
          printf("\nThe result is:     %.2lf\n", c);
          puts("______________________________________");
              
        }

          else if ( selection2=='e'|| selection2=='E'){
            break;
            }


      append_array(arr,c);
      }
      

      getchar();
      break;
    continue;
    
//Exit the program    
    case'E':
      puts("We hope you enjoyed using this calculator!");
      puts("Have a great day");
     
      puts("^  ########  ^");
      puts("  __________   ");
      
      asa ++;
      break;
      
//The memory access    
    case'M':
      Mf();

      getchar();
      break;
    continue;

//Erase the memory
    case'R':
      Rf();
      getchar();
      break;
    continue;

  ////////////////////////////////////////
    default :
      
      puts("\nError 404! No response to paging(^__^)");
      getchar();
    }
  }


} 


////////////////////////////////////////////////////////////////////
//costume functions
double varCreation(char varname, double v, double w, double y, double x, double z)
{
  double newnum;
  switch (varname)
  {

  case ('v'):
  case ('V'):
    newnum = v;
    break;
  case ('w'):
  case ('W'):
    newnum = w;
    break;
  case ('X'):
  case ('x'):
    newnum = x;
    break;
  case ('y'):
  case ('Y'):
    newnum = y;
    break;
  case ('z'):
  case ('Z'):
    newnum = z;
    break;
  
  }
  return newnum;
}
////////////////////////////////////////////////////////////////   
double varCreation2(char varname, double v, double w, double y, double x, double z)
{
  double newnum;
  switch (varname)
  {

  case ('v'):
  case ('V'):
    newnum = v;
    break;
  case ('w'):
  case ('W'):
    newnum = w;
    break;
  case ('X'):
  case ('x'):
    newnum = x;
    break;
  case ('y'):
  case ('Y'):
    newnum = y;
    break;
  case ('z'):
  case ('Z'):
    newnum = z;
    break;
  }
  return newnum;
}
  
/////////////////////////////////////////////////////////////////////

char opcheck(char op2)
{
  
  int i = 0;
  do
  {
    
    getchar();
    if (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == '%' || op2 == 'P' || op2 == 'X' || op2 == 'I' || op2 == 'p' || op2 == 'x' || op2 == 'i')
    { 
      if(op2=='/'){
        puts("enter a non-zero value");  
      }
      
      break;
    }
    else
    {
      printf("Invalid Input! Please enter a valid Operator. (+,-,*,/,%%,P,X,I)\n"); 
      scanf("%c", &op2);                                                     
      i = 2;                                                                        
    }
  } while (i == 2);

  return op2; //returns this operation to the main function
}
//////////////////////////////////////////////////////////////// 
char opcheck2(char op2)
{
  int i = 0;

  while(1)
  {
    getchar();
    
    if (op2 == 's' || op2 == 'S' || op2 == 'e' || op2 == 'E' || op2 == 'l' || op2 == 'L' || op2 == 'f' || op2 == 'F' || op2 == 'c' || op2 == 'C')
    {
      
      break;
    }
    else
    {
      printf("Invalid Input! Please enter a valid Operator. (S,E,L,F,C)\n"); 
      scanf("%c", &op2);                                                     
      continue;                                                                      
    }
  }

  return op2; //returns this operation to the main function
}

/////////////////////////////////////////////////////////////////
double options(){
  puts("______________________________________________________");
  printf("\n");
  printf("Select one of the following items:\n");
  printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
  printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
  printf("A) - Advances Mathematical Operations, using variables, arrays.\n");
  printf("V) - Define variables and assign them values.\n");
  printf("M) - Show values stored in Memory\n");
  printf("R) - Erase values stored in Memory\n");
  printf("E) - Exit.\n");
  
  
  char selection; 
  while(1){
    
    selection = getchar();
    
    if(selection == 'b'|| selection == 'B'||selection == 'u'||selection == 'U'||selection == 'a'||selection == 'A'||selection == 'v'||selection == 'V'||selection == 'm'||selection == 'M'||selection == 'r'||selection == 'R'||selection == 'e'||selection == 'E')
    {
      if(selection>'Z')
      {  
      selection = selection - 32;  
      }
      break;
    }
    else{
      printf("Please make a valid selection (B,U,A,V,M,R)\n");
      getchar();
      options();
    }
    break;
  }
  return selection;
}


////////////////////////////////////////////////////////////
double append_array(double arr[], double c){
  static int o=0;
  if(o<=100)
  {
    arr[o] = c;
    ++o;
  } 
  else {
    puts("Congratulations!!\n100 values have been stored in the memory and so its full\nif you wish to use the calculator for furthur calculations you need to restart the program!");
  }
  ans_count++; 
  return 0;
}
/////////////////////////////////////////////////////////////

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void Rf(){
  for(int i=0; i<=100;i++)
  {
    arr[i] = 0;
  }      
  ans_count = 0;
      
  puts("All the data in memory have been erased!");
  puts("########################################");  
}

///////////////////////////////////////////////////////////////
void Mf(){
  char ans_c;
  int ans_no;
  char keep_searching;

  while(1){
    if(ans_count == 0){
      printf("There are no answers saved in the memory!\n");
      printf("*****************************************\n)");
      break;
    }
    else
    {
      printf("");
      printf("\nThere is %d answer(s) saved in order!\nEnter the number of the calculation to print out the stored answer!\n(Enter 0 and to get all the answers and -1 to go back to main menu!)\n", ans_count);
      if(scanf("%d" , &ans_no)){
      
      
        if (ans_no -1 <= ans_count){

          if (ans_no == 0)
          {
            puts("$$$All the store values are:$$$");
            for(int i = 0;i <= ans_count-1; i++)
              {          
              printf("%d) %.2f \t", i+1,arr[i]);
              printf("\n");
              }            
          }
          else
          {
            printf("ANS NO.%d) %.2f ",ans_no, arr[ans_no-1]);
            puts("_____________________");
          }

        }

        else
          printf("There is no value on the entered position\n");
        
        
        //keep searching in the memory!?!
        printf("\nKeep searching in memory? (y or n)\n");
        getchar();
        scanf("%c", &keep_searching);
        
        
        if (keep_searching == 'y')
          continue;
        if (keep_searching =='n')
          break;
        else
          puts("\nInvalid answer, we'll return you to memory menu!");
      }
      else if (scanf("%c",&ans_c)){
        if (ans_c =='e')
        {
          
          break;
        }
        else{
          puts("Invalid entery");
          continue;
        }
      }
      
      
    }
  }
}
//////////////////////////////////////////////////////////////

void Vf(){
  char variable;
  
  
    
    while(variable !='v'||variable!='w'||variable!='x'||variable!='y'||variable!='z'){
    printf("please enter the name of the variable\na single character between 'v' and 'z'\n");
    getchar();
    scanf("%c", &variable);
    

      
    if(variable =='v'||variable=='V'){
      printf("please assign a value to the character:\n");
      scanf("%lf", &v);
      printf("Variable v has been assigned to:   %.2lf\n",v);
      break;}
    else if(variable =='w'||variable=='W'){
      printf("please assign a value to the character:\n");
      scanf("%lf", &w);
      printf("Variable w has been assigned to:   %.2lf\n",w);
      break;}
    else if(variable =='x'||variable=='X'){
      printf("please assign a value to the character:\n");
      scanf("%lf", &x); 
      printf("Variable x has been assigned to:   %.2lf\n",x);
      break;}
    else if(variable =='y'||variable=='Y'){
      printf("please assign a value to the character:\n");
      scanf("%lf", &y);
      printf("Variable y has been assigned to:   %.2lf\n",y);
      break;}
    else if(variable =='Z'||variable=='z'){
      printf("please assign a value to the character:\n");    
      scanf("%lf", &z);
      printf("Variable z has been assigned to:   %.2lf\n",z);
      break;}
    
    else{
      printf("Invalid input!\n");
      continue;}
    puts("_____________________");
  }

}

//####################################################################

double Bf(double a ,char op ,double b){
  
  double c;
  

  if (op == '+')
  {
    c = a + b;
    append_array(arr,c);
  }
  else if (op == '-')
  {
    c = a - b;
    append_array(arr,c);
  }
  else if (op == '*')
  {
    c = a * b;
    append_array(arr,c);
  }
  
  else if ( op == '/')
  {
    if (b == 0){
      do{
      printf("please enter a non-zero number:\n");
      scanf("%lf", &b);} while ( b == 0);}
    c = a / b;
    append_array(arr,c);
  }
  else if ( op == 'p'|| op=='P'){
    c = pow(a,b);
    append_array(arr,c);
  }
  else if(op=='x'|| op=='X')
  {
    if (a > b){ 
      c = a;
      append_array(arr,c);
    }
    else if (a ==b){
      printf("###############\nBoth numbers are same\n(neglect the result)\n");
    }
    
    else
    {
      c = b;
      append_array(arr,c);
    }
  }
  else if(op=='i' || op=='I'){
    if (a<b){
      c = a;
      append_array(arr,c);}
    else if(a==b){
      printf("###############\nBoth numbers are same\n(neglect the result)\n");     
      }
    else{
      c = b;
      append_array(arr,c);} 
  }
  return c;  
}
///////////////////////////////////////////////////////////////////
double get_pos(double e){
  
  
  while (1){
    
    
    if (e>=0)
    break;
    else{
      puts("enter a non-negative number:");
      scanf("%lf",&e);
      continue;
    }
  }
  return e;
    
}
///////////////////////////////////////////////////////////////////
double Uf(double a, char op){
  double c;
  
  
      if (op == 's' || op=='S' ){
        c = sqrt(a);   
      }

      else if ( op== 'l' || op == 'L'){       
        c = log10(a);
      }

      else if ( op=='E' | op == 'e'){
        c = exp(a);
      }
      
      else if ( op== 'C'|| op == 'c'){
        c = ceil(a);
      }

      else if ( op== 'f'|| op== 'F'){
        c = floor(a);
      }

  return c;
}

double Af(char selection2 , double a, char op, double b){
  double Bf(double a, char op, double b);
  double c;
  
  
  if (selection2 =='b'||selection2 =='B'){
    c = Bf(a,op,b);
  }
  else if(selection2 =='u' || selection2 == 'U'){
    c = Uf(a , op);
  }
  else if ( selection2 == 'e'|| selection2 == 'E'){
    options();
  }
  return c;

}
