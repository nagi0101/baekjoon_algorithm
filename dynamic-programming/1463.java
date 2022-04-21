import java.util.Scanner;

class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int N=sc.nextInt();
        
        int[] arr = new int[1000000+1];
        for(int i=0; i<arr.length; i++)
            arr[i]=-1;
        
        arr[1]=0;
        int ans = s(N, arr);
        
        System.out.println(ans);
    }
    
    public static int s(int N, int[] arr){
        if(arr[N]!=-1)
            return arr[N];
        
        int c1=1000000, c2=1000000, c3=1000000;
        if(N%2 == 0){
            c1 = arr[N/2] == -1 ? s(N/2, arr) : arr[N/2];
        }
        if(N%3 == 0){
            c2 = arr[N/3] == -1 ? s(N/3, arr) : arr[N/3];
        }
        c3 = arr[N-1] == -1 ? s(N-1, arr) : arr[N-1];
        
        arr[N] = Math.min(c1, Math.min(c2, c3)) + 1;
        return arr[N];
    }
}