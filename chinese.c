#include <stdio.h>

//defailt times twn x kai y
//a*y + b*x = gcd(a,b)

int x=0;
int y=1;

//kanoume diairesi a/b kai pairnume a=k*b + r
//opou diladi r=a%b kai thetouma a=b kai b=r (i b=a%b)
//epanalamvanoume wspou to r=0
int euklidis(int a, int b){
    //mexri to upoloipo na einai =0
    if (b==0){
        return a;
    }
    
    int g = euklidis(b, a%b);

    int x2 =x;
    //antistoixa kathe fora diatiroume tin sxesi upoloipou
    //opou to x exei tin sxesi 
    x = y - (a/b) * x;
    y = x2;
    return g;
    
}

int main(){

    //δεδομένα προβλήματος
    int a1 = 6;
    int a2 = 2;
    int a3 = 0;
    int n1=7;
    int n2=6;
    int n3=5;

    //υπολογισμός Ni = n/ni
    int n = n1*n2*n3;
    int N1 = n/n1;
    int N2 = n/n2;
    int N3 = n/n3;
    
    //Υπολογισμος των MTonos όπου MTonos = Ni ^-1 (mod ni)
    int M1T=N1%n1;
    int M2T=N2%n2;
    int M3T=N3%n3;

    int M1, M2, M3;

    
    //υπολογισμός αντιστρόφων για κάθε M Τόνος
    euklidis(M1T, n1);
    M1=y;    
    x=0;
    y=1;
    euklidis(M2T, n2);
    M2=y;    
    x=0;
    y=1;
    euklidis(M3T, n3);    
    M3=y;
    
    printf("%d %d %d", M1,M2,M3);

    //υπολογισμός αθροίσματος ai*Ni*Mi
    int x=a1*N1*M1 + a2*N2*M2 + a3*N3*M3;
    printf("\n%d", x);

    //εμφανιση του x όπου ισοδύναμο με το παραπάνω άθροισμα mod n
    int c = x%n;
    printf("\n%d", x%n);

    //οι ράβδοι χρυσού είναι 
    
    printf("\nΟι ράβδοι ήτανε: ");
    int i=0;
    for (i=0;i<5; i++){
        int ravdoi = c + n*i;
        if (ravdoi>0){
            printf("ή %d ", ravdoi);
        }
    }
    
}