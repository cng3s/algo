import sun.reflect.generics.tree.Tree;

import java.util.TreeMap;

public class HashTable<K, V> {

    private static final int upperTol = 10;
    private static final int lowerTol = 2;
    private static final int initCapcity = 7;

	// 哈希表使用RB树映射构建, K是哈希值, V是另一个TreeMap,里面存储了元素
    private TreeMap<K, V>[] hashtable; 
    private int M; // 哈希表长度
    private int size; // 哈希表的元素数量

    public HashTable(int M1) {
        M = M1;
        size = 0;
        hashtable = new TreeMap[M];
        for (int i = 0; i < M; i ++)
            hashtable[i] = new TreeMap<>();
    }
    public HashTable() { this(initCapcity); }


    private int hash(K key) {
        // 得到 key 的hashCode值
        return (key.hashCode() & 0x7fffffff) % M;
    }

    public int getSize() { return size; }

    public void add(K key, V val) {
        TreeMap<K, V> map = hashtable[hash(key)];
        if (!map.containsKey(key))
            size ++;
        map.put(key, val);

        if (size >= upperTol * M)
            resize(2 * M);
    }

    public V remove(K key) {
        TreeMap<K, V> map = hashtable[hash(key)];
        V ret = null;
        if (map.containsKey(key)) {
            ret = map.remove(key);
            size --;

            if (size < lowerTol * M && M / 2 > initCapcity)
                resize(M / 2);
        }
        return ret;
    }

    public void set(K key, V val) {
        TreeMap<K, V> map = hashtable[hash(key)];
        if (!map.containsKey(key))
            throw new IllegalArgumentException("set failed; key doesn't exist!");
        map.put(key, val);
    }

    public boolean contains(K key) { return hashtable[hash(key)].containsKey(key); }

    public V get(K key) { return hashtable[hash(key)].get(key); }

    private void resize(int newM) {
        TreeMap<K, V>[] newHashTable = new TreeMap[newM];
        for (int i = 0; i < newM; i ++)
            newHashTable[i] = new TreeMap<>();

        int oldM = M;
        this.M = newM;
        for (int i = 0; i < oldM; i ++) {
            TreeMap<K, V> map = hashtable[i];
            for (K key : map.keySet())
                newHashTable[hash(key)].put(key, map.get(key));
        }
        this.hashtable = newHashTable;
    }
}
