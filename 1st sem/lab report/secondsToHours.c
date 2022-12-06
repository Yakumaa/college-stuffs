// #include<stdio.h>
int main(){
    int s, h, m, sec;
    printf("enter no. of seconds: ");
    scanf("%d", &sec);
    h = sec / 3600;
    s = sec % 3600;
    m = s / 60;
    s = s % 60;
    printf("%d seconds = %d hours %d minutes %d sec", sec, h, m, s);
    return 0;
}
