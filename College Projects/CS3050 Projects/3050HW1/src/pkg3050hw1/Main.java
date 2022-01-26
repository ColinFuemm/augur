/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg3050hw1;

/**
 *
 * @author Colin
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int A[] = {99,6,1,45,0,3,27,9,8};
        InsertionSort(A);
        
        char B[] = {'A', 'L', 'P', 'H', 'A', 'B', 'E', 'T', 'I', 'C', 'A', 'L'};
        BubbleSort(B);
        
        System.out.println(howLongA(10));
    }
    
    public static int InsertionSort(int A[]){
        for(int i = 0; i < 8; i++) {
            if(A[i] > A[i+1]) {
                SwapInt(A, i);
                if (i > 0) i-= 2;
            }
        }
        System.out.printf("\nInsertion Sort Complete.");
        return A[0];
    }   
    public static void SwapInt(int A[], int i) {
        int temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
        System.out.printf("\n[ ");
        for(int j = 0; j < 9; j++) {
            if (j <= 7) { System.out.printf(A[j] + ", "); }
            else System.out.printf(A[j] + "] Cursor Position: " + A[i]);
        }
    }
    
    public static char BubbleSort (char B[]) {
        for(int j = 11; j > 0; j--) {
            for(int i = 0; i < j; i++)
                if(B[i] > B[i+1]) {
                    SwapChar(B, i);
                    
                }
        }
        System.out.printf("\nBubble Sort Complete.");
        return B[0];
    }
    public static void SwapChar(char B[], int i) {
        char temp = B[i];
        B[i] = B[i + 1];
        B[i + 1] = temp;
        System.out.printf("\n[ ");
        for(int j = 0; j < 12; j++) {
            if (j <= 10) { System.out.printf(B[j] + " "); }
            else System.out.printf(B[j] + "] Cursor Position: " + B[i]);
        }
    }
    
    //each time n increases by 2, the number of iterations in the first for loop (represented by k) increases by 1
    //the second for loop's iterations, resembled as kk, is the square of k because each time k increases by 1, 
    //the second for loop adds to kk what will be k's final value. this means the number of basic steps 
    //executed as a function of n is (n/2)^3 + 2, (+2 is for the additional two steps of declaring ints and returning the result)
    public static int howLongA(int n) {   //to find big-O we must ignore constants, so ( (n/2)^3 )
        int k = 0, kk = 0;                //becomes ( n^3 ) and +2 can be removed entirely 
        for(int i = 0; i <= n/2; i++) {   //therefore, the big-O of this problem is O(n^3)
            k++; 
            for(int j = 0; j <= n/2; j++) 
                kk++;             
            }
        return k*kk;
    }
    
    
    /*   

        Question Number 4 is located on the document turned in along with the assignment.

    



`   Question 5:
        a) A ternary heap would operate on a factor of three, where the binary heap operated on two.
           In terms of traversing the heap, for any given node i, the parent node will be i/3, 
           the left node (3i - 1), the central node 3i, and the right node (3i + 1) 
    
        b) The height of a ternary heap is log_3 (n)
    
        c) ExtractMax(A) {
                create temp field for max value
                replace top of heap with last value
                reduce heap size by 1
                Heapify(array, 1)  
                      left = (3i - 1) center = (3i) right (3i + 1)
                      compare left, center, right, and i to find largest
                      if largest is not i, swap i & largest and heapify(array, largest)
                return max
            } 
            Each operation within ExtractMax takes O(1) time besides the Heapify call, whose
            running time is relative to the height of the heap, or O(log_3 n).
    
        d) Insert(A, key) {
             increase heap size
             i = heap size
             A[i] = -infinity
             HeapSiftUp(A, i, key)               
                    A[i] = key
                    while (i > 1 & A[parent of i] < A[i]
                        swap(A[i], A[parent of i]
            }
            Each operation within Insert takes O(1) time besides HeapSiftUp().
            HeapSiftUp in turn takes time relative to the height of the heap, or O(log_3 n).
            therefore the total running time is O(log_3 n)
    
        e) IncreaseKey(A, i, k) {
                if k < A[i] return error
                else A[i] = k
                    HeapSiftUp(A, i, key)
            }
            This function checks one condition that takes O(1) and then HeapSiftUp described prior
            Total running time is again O(log_3 n)
    
    */
}
