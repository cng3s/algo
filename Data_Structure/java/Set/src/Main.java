import java.util.ArrayList;
public class Main {

    private static double testSet(Set<String> set, String filename) {
        long startTime = System.nanoTime();

        System.out.println("pride-and-prejudice");
        ArrayList<String> words = new ArrayList<>();
        if (FileOperation.readFile(filename, words)) {
            System.out.println("Total words: " + words.size());

            for (String word : words)
                set.add(word);
            System.out.println("Total different words: " + set.getSize());
        }

        long endTime = System.nanoTime();
        double time = (endTime - startTime) / 1000000000.0;
        return time;
    }

    public static void main(String[] args) {
        String filename = "pride-and-prejudice.txt";

        BSTSet<String> bstSet = new BSTSet<>();
        double time1 = testSet(bstSet, filename);
        System.out.println("BST Set: " + time1 + " s");

        System.out.println();

        LinkedListSet<String> linkedListSet = new LinkedListSet<>();
        double time2 = testSet(linkedListSet, filename);
        System.out.println("LinkedList Set: " + time2 + " s");

        System.out.println();

        AVLSet<String> as = new AVLSet<>();
        double time3 = testSet(as, filename);
        System.out.println("AVL Set: " + time3 + " s");
    }
}
