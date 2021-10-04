/*-----------------------------------------------------------------
The sieve of eretosthenes is one of the most efficient ways to 
find all primes smaller than n when n is smaller than 10 million.
-------------------------------------------------------------------*/
import java.util.*;

class SieveOfEratosthenes
{
    private static List<Integer> sieve(int n){
        
        List<Integer> list = new ArrayList<>();
        
        boolean prime[] = new boolean[n + 1];

        Arrays.fill(prime, true);
        
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]){
                // all multiples of p cannot be prime
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
 
        for (int i = 2; i <= n; i++){
            if (prime[i])
                list.add(i);
        }
        return list;
    }
    public static void main(String[] args) {
        
        int n = 50;
        List<Integer> primeNumbersList = sieve(n);
        
        for(int i=0; i<primeNumbersList.size(); i++)
            System.out.print(primeNumbersList.get(i) + " ");
            
    }
}