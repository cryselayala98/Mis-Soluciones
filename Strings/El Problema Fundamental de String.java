import java.util.*;
import java.lang.*;
import java.io.*;

//https://trainingcenter.cloud.ufps.edu.co/problemas/318/detalle/es

public class Main
{
	public static void main (String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String s = sc.next(); String p = sc.next();
			String k = kmp(s,p);
			
			if(k.length()==0)System.out.println("FALSE");
			else System.out.println("TRUE\n"+k);
		}
	}
	
	static String kmp(String cadena, String pattern) {
	int n=cadena.length();
	int m=pattern.length();
	String t = ""; int r = 0;
	ArrayList<Integer> tab=prefix_function(pattern);
	for(int i = 0, seen = 0; i < n; i++) {
		if(i<cadena.length() && seen<pattern.length() ){
		while(seen > 0 && cadena.charAt(i) != pattern.charAt(seen)) {
			seen = tab.get(seen-1);
		}
		if(cadena.charAt(i) == pattern.charAt(seen)) seen++;
		if(seen == m){
			if(r>0)t+=" ";
			t+=Math.abs(i-m+1); 
			seen = tab.get(seen-1);
			r++;
		} 
	}
	}
	return t;
}
	
	static ArrayList<Integer> prefix_function(String s) {
    int n = s.length(), len = 0, i = 1;
    ArrayList<Integer> lps = new ArrayList<>();
     Collections.fill(lps, n);
    for(int j = 0; j<n; j++)lps.add(-1); //llenar cada pos del lps
    lps.set(len, 0);
    while (i < n) {
        if (s.charAt(len) != s.charAt(i)) {
            if (len > 0) len = lps.get(len-1);
            else lps.set(i++, len);
        } else lps.set(i++, ++len);
    }
    //lps.add(0, -1); //Para SuffixLink
    return lps;
}
}
