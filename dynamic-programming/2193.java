import java.util.Scanner;

class Main {
    public static long[] O = new long[91];
    public static long[] E = new long[91];

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        for(int i=0; i<91; i++){
            O[i]=-1;
            E[i]=-1;
        }
        O[0]=0;
        O[1]=1;
        E[0]=0;
        E[1]=0;

        for(int i=2; i<=N; i++){
            O[i]=E[i-1];
            E[i]=E[i-1]+O[i-1];
        }

        System.out.println(O[N]+E[N]);
    }
}