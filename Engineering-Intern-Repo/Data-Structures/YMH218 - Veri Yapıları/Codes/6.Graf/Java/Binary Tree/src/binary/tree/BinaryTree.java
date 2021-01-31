package binary.tree;

/**
 *
 * @author Erdinç Dağlı
 */
class Node {
    public int data;
    public Node left,right;
}

public class BinaryTree {
    public Node root;
    public int NodeNumberFind(Node node)
    {
        if (node ==null) {
            return 0;
        }
        else if (node.left!=null || node.right!=null) {
            return node.data+NodeNumberFind(node.left)+NodeNumberFind(node.right);
        }
        return 0;
    }
    public void print(Node node)
    {
        System.out.println(node.data);
        NodeNumberFind(node.left);
        NodeNumberFind(node.right);
    }
    public void Add(int value)
    {
            Node pp = null;
            Node p = root; 
            while (p != null)
            {
                pp = p;
                if (value == p.data)
                    return; 
                else if (value < p.data)
                    p = p.left;
                else
                    p = p.right;
            }
            Node z = new Node();
            z.data = value;
            z.left = z.right = null;
            if (root == null)
                root = z; 
            else if (value < pp.data)
                pp.left = z;
            else
                pp.right = z;
        
    }
    public int leavesPlus(Node root)
    {
        if (root==null) {
            return 0;
        }
        if (root.left==null && root.right==null) {
            return root.data;
        }
        return leavesPlus(root.left)+leavesPlus(root.right);
    }
    public int leavesNumber(Node root)
    {
        if (root==null) {
            return 0;
        }
        if (root.left==null && root.right==null) {
            return 1;
        }
        return leavesNumber(root.left)+leavesNumber(root.right);
    }
    public int treeHeight(Node root)
    {
        if (root==null) {
            return 0;
        }
        return treeHeight(root.left)+1;
    }
    public int GeneralPlus(Node root)
    {
        if (root==null) {
            return 0;
        }
        return root.data+GeneralPlus(root.left)+GeneralPlus(root.right);
    }
    public int GeneralNumber(Node root)
    {
        if (root==null) {
            return 0;
        }
        return GeneralNumber(root.left)+GeneralNumber(root.right)+1;
    }
    public int JustNodePlus(Node root)
    {
        if (root==null) {
            return 0;
        }
        if (root.left!=null || root.right!=null) {
            return root.data;
        }
        return root.data+JustNodePlus(root.left)+JustNodePlus(root.right);
    }
    public int valueAdd(int data, Node root)
    {
        if (root==null) {
            return 0;
        }
        else if (root.data==data) {
            System.out.println("Değer Var");
        }
        else if(root.data<data)
        {
            valueAdd(data,root.right);
        }
        else if(root.data>data)
        {
            valueAdd(data,root.left);
        }
        return 0;
    }
    public Node max (Node root)
    {
        if (root==null) {
            return null;
        }
        Node p=root;
        while(p.right!=null){
            p=p.right;
        }
        return p;
    }
     public Node Min(Node root)
        {
            if (root == null)
                return null;
            Node p = root;
            while (p.left != null)
            {
                p = p.left;
            }
            return p;
        }
    public static void main(String[] args) {
        BinaryTree tree =new BinaryTree();
        Node root =new Node();
        root.data=5;
        tree.root=root;
        
        tree.Add(3);
        tree.Add(8);
        tree.Add(1);
        tree.Add(4);
        tree.Add(7);
        tree.Add(9);
        //tree.valueAdd(2, root);
        System.out.println("Ağacın Yapraklarının Toplamı :"+ tree.leavesPlus(root));
        System.out.println("Ağacın Yapraklarının Sayısı :"+tree.leavesNumber(root));
        System.out.println("Ağacın Yüksekliği : "+tree.treeHeight(root));
        System.out.println("Ağacın Bütün Düğümlerinin Toplamı : "+tree.GeneralPlus(root));    
        System.out.println("Ağaçtaki Bütün Düğümlerin Sayısı : "+tree.GeneralNumber(root));
        System.out.println("Ağaçtaki Sadece Düğümlerin Toplamı :"+tree.NodeNumberFind(root));
        //System.out.println("Ağacın En Büyük Elemanı : "+tree.Min(root));
    }
    
}
