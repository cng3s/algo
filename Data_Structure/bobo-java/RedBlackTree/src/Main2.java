import java.util.ArrayList;
import java.util.Random;

public class Main2 {

    public static void main(String[] args) {
        // 2千万随机数据做存储操作， 红黑树性能最好
        int n = 20000000;

        Random random = new Random();
        ArrayList<Integer> testdata = new ArrayList<>();
        for (int i = 0; i < n; i ++)
            testdata.add(random.nextInt(Integer.MAX_VALUE));

//        // test BST
        long startTime = System.nanoTime();
        BST<Integer, Integer> bst = new BST<>();

        for (Integer x : testdata)
            bst.add(x, null);

        long endTime = System.nanoTime();
        double time = (endTime - startTime) / 1000000000.0;
        System.out.println("BST: " + time + " s");
//
//
//        // test avl Tree
        startTime = System.nanoTime();
        AVLTree<Integer, Integer> avl = new AVLTree<>();

        for (Integer x : testdata)
            avl.add(x, null);

        endTime = System.nanoTime();
        time = (endTime - startTime) / 1000000000.0;
        System.out.println("AVL Tree: " + time + " s");

        // test RB Tree
        startTime = System.nanoTime();
        RBTree<Integer, Integer> rb = new RBTree<>();

        for (Integer x : testdata)
            rb.add(x, null);

        endTime = System.nanoTime();
        time = (endTime - startTime) / 1000000000.0;
        System.out.println("RB Tree: " + time + " s");
    }
}
