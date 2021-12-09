import java.time.Period;
import java.util.*;

class Values {
    static int sumval[] = new int[100];
    static int longest[] = new int[100];
    static int place[] = new int[100];
}

public class Solution {
    void KMPSearch(String pat, String txt, int totalnumberint) {
        int M = pat.length();
        int N = txt.length();

        int lps[] = new int[M];
        int j = 0;

        int sum, flag = 0;
        sum = computeLPSArray(pat, M, lps);

        int previous = 0, p4 = 0;
        int place = -1, koreflag = 0;
        int i = 0;
        while (i < N) {
            if (pat.charAt(j) == txt.charAt(i)) {
                j++;
                i++;
                if (koreflag == 0) {
                    place = 0;
                    koreflag++;
                }

            }

            if (j == M) {

                j = lps[j - 1];
            }
            if (j > previous) {
                previous = j;
                place = i - j;

            }

            else if (i < N && pat.charAt(j) != txt.charAt(i)) {

                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        if (place != -1) {
            for (int ikr = 0; ikr < M; ikr++) {
                if (place + ikr < N) {
                    if (pat.charAt(ikr) == txt.charAt(place + ikr)) {
                        p4++;

                        flag++;
                    } else if (flag != 0) {
                        break;
                    }
                }
            }
        }

        Values.sumval[totalnumberint] = sum;
        Values.longest[totalnumberint] = p4;
        Values.place[totalnumberint] = place;
        totalnumberint = totalnumberint + 1;

    }

    int computeLPSArray(String pat, int M, int lps[]) {

        int len = 0;
        int i = 1, sum = 0;
        lps[0] = 0;

        while (i < M) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
                sum = sum + 1;
            } else {

                if (len != 0) {
                    len = lps[len - 1];

                } else {
                    lps[i] = len;
                    i++;
                }
            }
        }

        return sum;
    }

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        String totalnumber = in.nextLine();
        String textthaa, paternthaa;
        int totalnumberint = Integer.parseInt(totalnumber);
        for (int i = 0; i < totalnumberint; i++) {
            textthaa = in.nextLine();
            textthaa = textthaa.toUpperCase();
            paternthaa = in.nextLine();
            paternthaa = paternthaa.toUpperCase();
            new Solution().KMPSearch(paternthaa, textthaa, i);
        }
        for (int j = 0; j < totalnumberint; j++) {
            System.out.print(Values.sumval[j] + " ");
            System.out.print(Values.longest[j] + " ");
            System.out.println(Values.place[j]);
        }

    }
}