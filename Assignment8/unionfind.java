import java.util.Scanner;

public class unionfind {
    private int[] veetukar;
    private int[] makkal;

    public unionfind(int valuppam) {
        veetukar = new int[valuppam];
        makkal = new int[valuppam];
        for (int i = 0; i < valuppam; i++) {
            veetukar[i] = i;
            makkal[i] = 1;
        }
    }

    public int noof(int kopp) {
        return makkal[kandupidikk(kopp)];
    }

    public int rootkandupveetukarikan(int kopp) {
        return kandupidikk(kopp);
    }

    public int ethrayennam(int[] sanangal) {
        int verpettathethra = 0;
        for (int i = 0; i < sanangal.length; i++) {
            if (kandupidikk(sanangal[i]) == sanangal[i]) {
                verpettathethra = verpettathethra + 1;
            }
        }
        return verpettathethra;
    }

    public int kandupidikk(int p) {
        while (p != veetukar[p])
            p = veetukar[p];
        return p;
    }

    public int azham(int p) {
        int azhamenn = 0;
        for (int i = 0; p != kandupidikk(p); i++) {
            azhamenn = azhamenn + 1;
            p = veetukar[p];
        }
        return azhamenn;
    }

    public int kudapirappukal(int p, int[] ithaan) {
        int siblno = 0;
        for (int i = 0; i < ithaan.length; i++) {
            if (kandupidikk(p) == kandupidikk(ithaan[i]) && azham(p) == azham(ithaan[i])) {
                siblno = siblno + 1;
            }
        }
        return (siblno - 1);
    }

    public void union(int p, int q) {
        int i = kandupidikk(p);
        int j = kandupidikk(q);
        if (i == j)
            return;

        if (makkal[i] < makkal[j]) {
            veetukar[i] = j;
            makkal[j] += makkal[i];
        } else {
            veetukar[j] = i;
            makkal[i] += makkal[j];
        }
    }

    public static void main(String[] args) {
        unionfind sadhanam = new unionfind(66);

        Scanner in = new Scanner(System.in);
        String line1 = in.nextLine();
        String line2 = in.nextLine();
        String[] arrOfStr1 = line1.split(" ");
        String[] arrOfStr2 = line2.split(" ");
        int siz = Integer.parseInt(arrOfStr1[0]);
        int[] sanangal = new int[siz];
        for (int i = 1; i <= arrOfStr1.length - 1; i++) {
            sanangal[i - 1] = Integer.parseInt(arrOfStr1[i]);
        }
        for (int i = 1; i <= arrOfStr2.length - 1; i = i + 2) {
            sadhanam.union(Integer.parseInt(arrOfStr2[i]), Integer.parseInt(arrOfStr2[i + 1]));
        }
        String eachline;
        eachline = in.nextLine();
        String[] thannasadhanam = eachline.split(" ");
        if (thannasadhanam[0].equals("N")) {
            System.out.println(sadhanam.ethrayennam(sanangal));
        } else if (thannasadhanam[0].equals("Z")) {
            for (int i = 2; i < thannasadhanam.length; i++) {
                System.out.print(sadhanam.noof(Integer.parseInt(thannasadhanam[i])));
                System.out.print(" ");
            }
        } else if (thannasadhanam[0].equals("F")) {
            for (int i = 2; i < thannasadhanam.length; i++) {
                System.out.print(sadhanam.kandupidikk(Integer.parseInt(thannasadhanam[i])));
                System.out.print(" ");

            }
        } else if (thannasadhanam[0].equals("D")) {
            for (int i = 2; i < thannasadhanam.length; i++) {
                System.out.print(sadhanam.azham(Integer.parseInt(thannasadhanam[i])));
                System.out.print(" ");

            }
        } else if (thannasadhanam[0].equals("S")) {
            for (int i = 2; i < thannasadhanam.length; i++) {
                System.out.print(sadhanam.kudapirappukal(Integer.parseInt(thannasadhanam[i]), sanangal));
                System.out.print(" ");

            }
        }
    }
}