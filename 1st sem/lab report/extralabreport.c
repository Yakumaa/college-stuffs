#include <stdio.h>
#include <math.h>
int main(){
    int a, b, c, d;
    float s, root1, root2, root;
    printf("enter coeff: ");
    scanf("%d %d %d", &a, &b, &c);

    d = b * b - 4 *a * c;

    if (d<0)
    {
        printf("Roots are imagunary");
    }
    else if(d == 0){
        root1 = -b/(2*a);
        printf("both roots are same and is %.2d", root1);
    }
    else{
        s = sqrt(d);
        root1 = (-b + s)/ (2*a);
        root2 = (-b - s)/ (2*a);
        printf("root1 = %.2f \nroot2 = %.2f",root1, root2);
    }    

    return 0;





// #include<stdio.h>
// int main(){
//     int a, b, c;
//         printf("Enter a number: ");
//         scanf("%d", &c);
        
//         for(int a = 0; a*a <= c; a++)
//         {
//             for (int b = 0; b*b <= c; b++)
//             {
//                 if(a*a + b*b == c)
//                 {
//                    printf("yes");
//                 }               
//             }               
//         }

//     return 0;
// }









