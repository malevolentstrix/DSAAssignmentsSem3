import java.util.Scanner;

public class unionfind {
    private int[] parent;
    private int[] childern;
    private int[] rank;

    public unionfind(int size) {
        parent = new int[size];
        childern = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            childern[i] = 1;
            rank[i] = 0;
        }
    }

    public int numberofnodes(int nodesinthiselement) {
        return childern[find(nodesinthiselement)];
    }

    public int findtheroot(int nodesinthiselement) {
        return find(nodesinthiselement);
    }

    public int numberoftrees(int[] elements) {
        int countofthedisjointsets = 0;
        for (int i = 0; i < elements.length; i++) {
            if (find(elements[i]) == elements[i]) {
                countofthedisjointsets = countofthedisjointsets + 1;
            }
        }
        return countofthedisjointsets;
    }

    public int find(int p) {
        while (p != parent[p])
            p = parent[p];
        return p;
    }

    public int depth(int p) {
        int depthcount = 0;
        while (p != find(p)) {
            depthcount = depthcount + 1;
            p = parent[p];
        }
        return depthcount;
    }

    public int siblings(int p, int[] elements) {
        int siblno = 0;
        for (int i = 0; i < elements.length; i++) {
            if (find(p) == find(elements[i]) && depth(p) == depth(elements[i])) {
                siblno = siblno + 1;
            }
        }
        return (siblno - 1);
    }

    public void union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j)
            return;

        else if (rank[i] < rank[j]) {
            parent[i] = j;
            childern[j] += childern[i];
        } else if (rank[i] > rank[j]) {
            parent[j] = i;
            childern[i] += childern[j];
        } else {
            if (j > i) {
                int tempvar = j;
                j = i;
                i = tempvar;
            }
            parent[j] = i;
            childern[i] += childern[j];
            rank[i]++;
        }

    }

    public static void main(String[] args) {
        unionfind object = new unionfind(200);

        Scanner in = new Scanner(System.in);
        String line1 = in.nextLine();
        String line2 = in.nextLine();
        String[] arrOfStr1 = line1.split(" ");
        String[] arrOfStr2 = line2.split(" ");
        int siz = Integer.parseInt(arrOfStr1[0]);
        int[] elements = new int[siz];
        for (int i = 1; i <= arrOfStr1.length - 1; i++) {
            elements[i - 1] = Integer.parseInt(arrOfStr1[i]);
        }
        for (int i = 1; i <= arrOfStr2.length - 1; i = i + 2) {
            object.union(Integer.parseInt(arrOfStr2[i]), Integer.parseInt(arrOfStr2[i + 1]));
        }
        String eachline;
        eachline = in.nextLine();
        String[] line = eachline.split(" ");
        if (line[0].equals("N")) {
            System.out.println(object.numberoftrees(elements));
        } else if (line[0].equals("Z")) {
            for (int i = 2; i < line.length; i++) {
                System.out.print(object.numberofnodes(Integer.parseInt(line[i])));
                System.out.print(" ");
            }
        } else if (line[0].equals("F")) {
            for (int i = 2; i < line.length; i++) {
                System.out.print(object.find(Integer.parseInt(line[i])));
                System.out.print(" ");

            }
        } else if (line[0].equals("D")) {
            for (int i = 2; i < line.length; i++) {
                System.out.print(object.depth(Integer.parseInt(line[i])));
                System.out.print(" ");

            }
        } else if (line[0].equals("S")) {
            for (int i = 2; i < line.length; i++) {
                System.out.print(object.siblings(Integer.parseInt(line[i]), elements));
                System.out.print(" ");

            }
        }
    }
}