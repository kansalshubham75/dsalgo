import java.util.HashSet;
public class test {

    private static boolean isPalindrome(char[] s1) {
        HashSet<Character> hs = new HashSet<>();
        for(char c: s1) {
            if(hs.contains(c)) {
                hs.remove(c);				
            }				
            else {
                hs.add(c);
            }				
        }
        return hs.size() < 2;
    }
    
    private static void swap(char[] s2, int i, int j) {
        char tmp = s2[i];
        s2[i] = s2[j];
        s2[j] = tmp;
    }
    
    public static int minswaps(String s) {
        char[] s1=s.toCharArray();
        int result = 0;
        if(!isPalindrome(s1))
            return -1;
        int i = 0;
        int j = s1.length - 1;
        int k = j;
        while(i < j) {
            k = j;
            while(s1[i] != s1[k] && k > i)
                k--;
            if(s1[i] == s1[k] && i != k) {
                while(k < j) {
                    swap(s1,k,k+1);
                    k++;
                    result++;
                }
                i++;
                j--;
            }
            else {
                swap(s1,i,i+1);
                result++;
            }
            
        }
        return result;
    }
    public static void main(String[] args) {
        System.out.println(minswaps("abcbbbccca"));
    }
}