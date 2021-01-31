package sıralamaalgoritmalari;

/**
 *
 * @author Erdinç Dağlı
 */
class Sort
{
    public void bublesort(int[]x)
    {
        int n=x.length;
        int temp,j,pass;
        for (pass = 0; pass < n-1; pass++) {
            for (j = 0; j < n-1-pass; j++) {
                if (x[j]>x[j+1]) {
                    temp=x[j];
                    x[j]=x[j+1];
                    x[j+1]=temp;
                }
            }
        }
    }
    public void quicksort(int input[],int left,int right)
    {
        int pivot=Partition(input,left,right);
        if (left<pivot)  quicksort(input,left,pivot-1);
        
        if (right>pivot) quicksort(input,pivot+1,right);
            
            
    
        
    }
    
    public int Partition(int numbers[],int left,int right)
    {
        int leftHold,rightHold,i,pivot;leftHold=left;rightHold=right;
        pivot=numbers[left];
        while(left<right)
        {
            while(numbers[right]>=pivot&&left<right) right--;
            if (left!=right) {
                numbers[left]=numbers[right];left++;
                while(numbers[right]<=pivot&&left<right) left++;
                if (left!=right) {
                    numbers[right]=numbers[left];right--;
                }
            }
            
        }
        numbers[left]=pivot;
        pivot=left;
        left=leftHold;
        right=leftHold;
        return pivot;
    }
    public  int [] selectionsort(int []A,int n)
    {
        int temp,min;
        for (int i = 0; i < n-1; i++) {
            min=i;
            for (int j = i; j < n-1; j++) {
                if (A[j]<A[min]) {
                    min=j;
                }
            }
            temp=A[i];A[i]=A[min];A[min]=temp;
        }
        return A;
    }
    public void insertsort(int x[],int n){
        int i,k,y;
        for (k = 1; k < n; k++) {
            y=x[k];
            for (i = k-1; i >=0&&y<x[i] ; i--) {
                x[i+1]=x[i];
                
            }
            x[i+1]=y;
        }
    }
    /*public void radixSort(int[]arr){
        if (arr.length==0) {
            return ;
        }
        int[][]np=new int [arr.length][2];
        int []q=new int [0x100];
        int k,l,i,j,f;
        for (k = 0; k < 4; k++) {
            for (i = 0; i < np.length; i++) {
                np[i][1]=i+1;
                
            }
            np[i][1]=-1;
            for (i = 0; i < q.length; i++) {
                q[i]=-1;
            }
            for (f = 0; f < arr.length; f++) {
                j=((0xFF<<(k<<3))&arr[i])>>(k<<3);
                if (q[j]==-1) {
                    l=q[j]=f;
                }
                else{
                    l=q[j];
                    while(np[l][l]!=-1)
                    {
                        l=no[l][1];
                    }
                    
                }
               np[l][1]=f;
                    1=np[l][1];
            }
                f=np[f][1];
                np[l][0]=arr[i];
                np[l][l]=-1;
            
        }
        for (1 = q[i=j=0]; i < 0x100; i++) {
                for (l = q[i]; l != -1; 1=np[l][1]) {
                    arr[j++]=np[1][0];
                }
            }
    }*/
    
}
class mergeSort{
    private int [] list;
    public mergeSort(int[]listToSort){
        list=listToSort;
    }
    public int[] getList(){
        return list;
    }
    public void sort(){
        list=sort(list);
    }
    private int[]  sort(int[]whole)
    {
        if (whole.length==1) {
            return whole;
        }
        else{
            int[]left=new int[whole.length/2];
            System.arraycopy(whole,0,left,0,left.length);
            int []right=new int[whole.length-left.length];
            System.arraycopy(whole, left.length, right, 0, right.length);
            left=sort(left);
            right=sort(right);
            merge(left,right,whole);
            return whole;
        }
    }
    private void merge(int[] left,int[]right,int[]result)
    {
        int x=0,y=0,k=0;
        while(x<left.length&&y<right.length)
        {
            if (left[x]<right[y]) {
                result[k]=left[x];x++;
            }
            else{
                result[k]=right[y];y++;
            }
            k++;
        }
        int []rest;int restIndex;
        if (x>=left.length) {
            rest=right;
            restIndex=y;
        }
        else{
            rest=left;
            restIndex=x;
        }
        for (int i = restIndex; i < rest.length; i++) {
            result[k]=rest[i];k++;
        }
    }
}

public class SıralamaAlgoritmalari {
    
    
    public static void main(String[] args) {
        
        Sort s =new Sort();
        int a[]={2,1,12,3,15};
        System.out.print("1.BUBBLE SORT\nArray Before Bubble Sort \n");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
        s.bublesort(a);
        System.out.print("\nArray After Bubble Sort \n");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
        Sort s1 =new Sort();
        int b[]={23,398,34,100,57,67,55,320};
        System.out.print("\n2.QUICK SORT\nArray Before Quick Sort \n");
        for (int i = 0; i < b.length; i++) {
            System.out.print(b[i]+" ");
        }
        s1.quicksort(b, 0, b.length-1);
        System.out.print("\nArray After Quick Sort \n");
        for (int i = 0; i < b.length; i++) {
            System.out.print(b[i]+" ");
        } 
        Sort s3 =new Sort();
        int c[]={2,38,34,100,5,7,57,30,11,52,57,44};
        System.out.print("\n3.SELECTION SORT\nArray Before Selection Sort \n");
        for (int i = 0; i < c.length; i++) {
            System.out.print(c[i]+" ");
        }
        s3.selectionsort(c, c.length+1);
        System.out.print("\nArray After Selection Sort \n");
        for (int i = 0; i < c.length; i++) {
            System.out.print(c[i]+" ");
        } 
        Sort s4 =new Sort();
        int d[]={12,42,22,1,0,11};
        System.out.print("\n4.INSERTION SORT\nArray Before Inserttion Sort \n");
        for (int i = 0; i < d.length; i++) {
            System.out.print(d[i]+" ");
        }
        s4.insertsort(d, d.length);
        System.out.print("\nArray After Insertion Sort \n");
        for (int i = 0; i < d.length; i++) {
            System.out.print(d[i]+" ");
        } 
        int []sortObj={122,42,2,1,10,11,-1,-21};
        System.out.print("\n4.MERGE SORT\nArray Before Merge Sort \n");
        for (int i = 0; i < sortObj.length; i++) {
            System.out.print(sortObj[i]+" ");
        }
        mergeSort sortOb=new mergeSort(sortObj);
        sortOb.sort();
        int[]seqArray=sortOb.getList();
        System.out.print("\nArray After Merge Sort \n");
        for (int i = 0; i < seqArray.length; i++) {
            System.out.print(seqArray[i]+" ");
        } 
    }
    
}
