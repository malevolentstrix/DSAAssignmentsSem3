import java.util.Scanner;
import java.text.DecimalFormat;

class Node {
    int key, height;
    Node left, right;

    Node(int d) {
        key = d;
        height = 1;
    }
}

class AVLhackerrank {
    Node root;
    int sumk = 0, number = 0;

    int height(Node N) {
        if (N == null)
            return 0;
        return N.height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        y.height = max(height(y.left), height(y.right)) + 1;
        x.height = max(height(x.left), height(x.right)) + 1;

        return x;
    }

    Node leftRotate(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        y.left = x;
        x.right = T2;

        x.height = max(height(x.left), height(x.right)) + 1;
        y.height = max(height(y.left), height(y.right)) + 1;

        return y;
    }

    int getBalance(Node N) {
        if (N == null)
            return 0;
        return height(N.left) - height(N.right);
    }

    Node insert(Node node, int key) {
        if (node == null)
            return (new Node(key));

        if (key < node.key)
            node.left = insert(node.left, key);
        else if (key > node.key)
            node.right = insert(node.right, key);
        else
            return node;

        node.height = 1 + max(height(node.left), height(node.right));

        int balance = getBalance(node);

        if (balance > 1 && key < node.left.key)
            return rightRotate(node);

        if (balance < -1 && key > node.right.key)
            return leftRotate(node);

        if (balance > 1 && key > node.left.key) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node.right.key) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }

    Node minValueNode(Node node) {
        Node current = node;

        while (current.left != null)
            current = current.left;

        return current;
    }

    Node maxValueNode(Node node) {
        Node current = node;

        while (current.right != null)
            current = current.right;

        return current;
    }

    Node deleteNode(Node root, int key) {

        if (root == null)
            return root;

        if (key < root.key)
            root.left = deleteNode(root.left, key);

        else if (key > root.key)
            root.right = deleteNode(root.right, key);

        else {

            if ((root.left == null) || (root.right == null)) {
                Node temp = null;
                if (temp == root.left)
                    temp = root.right;
                else
                    temp = root.left;

                if (temp == null) {
                    temp = root;
                    root = null;
                } else
                    root = temp;

            } else {

                Node temp = minValueNode(root.right);

                root.key = temp.key;

                root.right = deleteNode(root.right, temp.key);
            }
        }

        if (root == null)
            return root;

        root.height = max(height(root.left), height(root.right)) + 1;

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root.left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root.left) < 0) {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root.right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root.right) > 0) {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }

        return root;
    }

    Node find(int key) {
        Node current = root;
        while (current != null) {
            if (current.key == key) {
                break;
            }
            current = current.key < key ? current.right : current.left;
        }
        return current;
    }

    void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.key + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    int sumds(Node node) {
        if (node != null) {
            sumk = sumk + node.key;
            sumds(node.left);
            sumds(node.right);
        }
        return sumk;
    }

    int numberof(Node node) {
        if (node != null) {
            number = number + 1;

            numberof(node.left);
            numberof(node.right);
        }
        return number;
    }

    int numberwrap(Node node) {
        number = 0;
        return numberof(node);
    }

    int sumwrap(Node node) {
        sumk = 0;
        return sumds(node);
    }

    public static void main(String[] args) {
        AVLhackerrank tree = new AVLhackerrank();

        Scanner in = new Scanner(System.in);
        String totalnumber = in.nextLine();
        String eachline;
        int totalnumberint = Integer.parseInt(totalnumber);
        for (int i = 0; i < totalnumberint; i++) {
            eachline = in.nextLine();
            String[] arrOfStr = eachline.split(" ");
            if (arrOfStr[0].equals("A")) {

                for (int j = 1; j <= arrOfStr.length - 1; j++) {
                    int insertint = Integer.parseInt(arrOfStr[j]);
                    tree.root = tree.insert(tree.root, insertint);
                }
            } else if (arrOfStr[0].equals("R")) {

                for (int j = 1; j <= arrOfStr.length - 1; j++) {
                    int deleteint = Integer.parseInt(arrOfStr[j]);
                    tree.root = tree.deleteNode(tree.root, deleteint);
                }
            } else {
                String[] arrOfStr_elsecase = eachline.split(" ");
                for (int j = 0; j <= arrOfStr_elsecase.length - 1; j++) {
                    int findint = Integer.parseInt(arrOfStr_elsecase[j]);
                    Node thisisit = tree.find(findint);
                    if (thisisit != null) {
                        Node TempRoot = thisisit;
                        System.out.print(tree.height(TempRoot));
                        System.out.print(" " + tree.minValueNode(TempRoot).key);
                        System.out.print(" " + tree.maxValueNode(TempRoot).key);
                        int sum = tree.sumwrap(TempRoot);
                        double avg = (sum * 1.0) / tree.numberwrap(TempRoot);
                        DecimalFormat df = new DecimalFormat("###.#");
                        System.out.println(" " + df.format(avg));
                    } else
                        System.out.println("-1");
                }
            }
        }
    }
}
