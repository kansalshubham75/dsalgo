import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

public class Btree {
	static Node root;

	public static class Node {
		int data;
		Node l, r;

		Node(int data, Node l, Node r) {
			this.data = data;
			this.l = l;
			this.r = r;
		}

		Node() {
			data = 0;
			l = null;
			r = null;
		}
	}

	// =========================CREATION USING
	// PREORDER,SIZE,HEIGHT,DISPLAY====================//
	public int size(Node node) {
		if (node == null)
			return 0;
		return size(node.l) + size(node.r) + 1;
	}

	public static int height(Node node) {
		if (node == null)
			return 0;
		return Math.max(height(node.l), height(node.r)) + 1;
	}

	public void construct(int[] arr,int idx) {
		root = createUsingPre(arr,idx);
	}

	// static int idx = 0;

	private Node createUsingPre(int[] arr,int idx) {
		if (idx >= arr.length || arr[idx] == -1) {
			return null;
		}
		Node node = new Node(arr[idx], null, null);
		node.l = createUsingPre(arr,idx+1);
		node.r = createUsingPre(arr,idx+2);
		return node;
	}

	public static void display(Node node) {
		if (node == null) {
			return;
		}
		String str = "";
		str += node.l == null ? " . " : node.l.data;
		str += " -> " + node.data + " <- ";
		str += node.r == null ? " . " : node.r.data;
		System.out.println(str);

		display(node.l);
		display(node.r);
	}

	// =================FIND : BOOLEAN,NODE RETURN
	// TYPE====================================//
	public static boolean find(Node node, int data) {
		if (node == null) {
			return false;
		}
		if (node.data == data) {
			return true;
		}
		boolean res = false;
		res = res || find(node.l, data);
		res = res || find(node.r, data);

		return res;
	}

	public static Node find_02(Node node, int data) {
		if (node == null) {
			return null;
		}
		if (node.data == data) {
			return node;
		}
		Node res = find_02(node.l, data);
		if (res != null) {
			return res;
		}
		res = find_02(node.r, data);
		if (res != null) {
			return res;
		}

		return null;
	}

	// ==================LEVEL ORDER TRAVERSAL USING QUEUE=======================//
	public static void levelOrder_01(Node root) {
		LinkedList<Node> q = new LinkedList<>();
		q.addLast(root);
		int level = 0;
		while (q.size() != 0) {
			System.out.print("Level " + level + "->");
			int size = q.size();
			while (size-- > 0) {
				Node f = q.removeFirst();
				System.out.print(f.data + " ");
				if (f.l != null) {
					q.addLast(f.l);
				}
				if (f.r != null) {
					q.addLast(f.r);
				}
			}
			level++;
			System.out.println();
		}
	}

	public static void levelOrder_02(Node root) { // Using null in queue
		LinkedList<Node> q = new LinkedList<>();
		q.addLast(root);
		q.addLast(null);
		int level = 0;
		System.out.print("Level " + level + "->");
		while (q.size() > 1) {
			if (q.getFirst() == null) {
				q.removeFirst();
				q.addLast(null);
				level++;
				System.out.println();

				System.out.print("Level " + level + "->");
			}
			Node f = q.removeFirst();
			System.out.print(f.data + " ");
			if (f.l != null) {
				q.addLast(f.l);
			}
			if (f.r != null) {
				q.addLast(f.r);
			}

		}
	}

	// ==================ROOT TO NODE PATH==================//
	public static ArrayList<Node> rootToNodePath(Node node, int data) {
		if (node == null) {
			return new ArrayList<Node>();
		}
		if (node.data == data) {
			ArrayList<Node> foundnode = new ArrayList<>();
			foundnode.add(node);
			return foundnode;
		}
		ArrayList<Node> res = new ArrayList<>();
		res = rootToNodePath(node.l, data);
		if (!res.isEmpty()) {
			res.add(node);
			return res;
		}
		res = rootToNodePath(node.r, data);
		if (!res.isEmpty()) {
			res.add(node);
			return res;
		}

		return res;
	}

	// ===================DIAMETER OF THE TREE=============================//
	public static int diameter_01(Node node) {
		if (node == null) {
			return 0;
		}
		int lh = height(node.l);
		int rh = height(node.r);

		int ld = diameter_01(node.l);
		int rd = diameter_01(node.r);

		return Math.max(Math.max(ld, rd), lh + rh + 1);

	}

	public static int[] diameter_02(Node node) {
		if (node == null) {
			return new int[2];
		}

		int[] left = diameter_02(node.l);
		int[] right = diameter_02(node.r);

		int[] myAns = new int[2];
		myAns[0] = Math.max(Math.max(left[0], right[0]), left[1] + right[1] + 1);
		myAns[1] = Math.max(left[1], right[1]) + 1;

		return myAns;
	}

	// ==================FIND NODE K EDGES AWAY FROM GIVEN NODE===================//
	public static void kaway(Node node, int k, Node rnode) {
		if (node == null || node == rnode)
			return;
		if (k == 0) {
			System.out.print(node.data + " ");
			return;
		}
		kaway(node.l, k - 1, rnode);
		kaway(node.r, k - 1, rnode);
	}

	public static void kfar_01(Node node, int k, int data) {
		ArrayList<Node> rTNP = rootToNodePath(node, data);
		Node rnode = null;

		for (int i = 0; i < rTNP.size(); i++) {
			kaway(rTNP.get(i), k - i, rnode);
			rnode = rTNP.get(i);
		}
	}

	// public static int kfar(Node node,int k, int data) {
	// if (node==null)
	// return -1;
	// if(node.data==data) {
	// kaway(node,k,null);
	// }
	// int ld=kfar();
	// }
	public static class AllPair {
		int size;
		int height;
		boolean find = false;

		int ciel = (int) 1e8;
		int floor = (int) -1e8;
		Node pred = null;
		Node succ = null;
		Node prev = null;
	}
	// public static void allSol(Node node,)

	// public static void kAway(Node root,int data,int k) {
	// LinkedList<Node> ll=new LinkedList<>();
	// ll.addLast(node);
	//
	// }
	// ===============================CHECK FOR
	// BST=================================//
	static int prev = (int) -1e8;

	public static boolean isBST(Node node) {
		if (node == null) {
			return true;
		}
		if (!isBST(node.l)) {
			return false;
		}
		if (prev > node.data) {
			return false;
		}
		prev = node.data;
		if (!isBST(node.r)) {
			return false;
		}

		return true;
	}

	// ===================================NO. OF BST's ,SIZE & ROOT OF LARGEST BST===============//
	public static class BSTpair {
		boolean isBST = true;
		int count = 0;
		int size = 0;
		Node lnode = null;

		int max = (int) -1e8;
		int min = (int) 1e8;
	}

	public static BSTpair bstSol(Node node) {
		if (node == null) {
			return new BSTpair();
		}
		BSTpair mySol = new BSTpair();
		BSTpair left = bstSol(node.l);
		BSTpair right = bstSol(node.r);
		mySol.count = left.count + right.count;
		if (left.isBST && right.isBST && left.max < node.data && right.min >= node.data) {
			mySol.count += 1;
			mySol.size = mySol.count;
			mySol.lnode = node;
		} else {
			mySol.size = Math.max(left.size, right.size);
			mySol.isBST = false;
			if (right.size >= left.size) {
				mySol.lnode = right.lnode;
			} else {
				mySol.lnode = left.lnode;
			}
		}
		mySol.max = Math.max(Math.max(left.max, right.max), node.data);
		mySol.min = Math.min(Math.min(left.min, right.min), node.data);

		return mySol;
	}

	// ================================LEFT Linearize BINARY TREE===========================//
	public static Node linearize(Node node) {
		if (node == null)
			return null;
		if (node.l == null && node.r == null) {
			return node;
		}
		Node leftTail = linearize(node.l);
		Node rightTail = linearize(node.r);
		if (leftTail == null) {
			node.l = node.r;
		} else {
			leftTail.l = node.r;
		}
		node.r = null;

		return rightTail != null ? rightTail : leftTail;
	}

	// public static void convertBST(Node prev,Node node){
	// if(node==null){
	// return;
	// }
	// if(prev==null){
	// return;
	// }
	// convertBST(node,node.l);
	// convertBST(node,node.r);
	// if(prev.l!=null){
	// prev.l.l=node;
	// prev.r=null;
	// }else{
	// prev.l=node;
	// }
	// }

	// ==========================TREE TO DLL=========================//
	static Node prev_ = null;
	static Node head_ = null;

	public static void treeToDLL(Node node) {
		if (node == null) {
			return;
		}
		treeToDLL(node.l);
		if (head_ == null) {
			head_ = node;
		}
		prev_ = node;

		treeToDLL(node.r);
	}

	// =====================================Path Sum=========================//
	public static boolean pathSum_I(Node node, int tar) {
		if (node == null)
			return false;
		if (node.l == null && node.r == null && tar - node.data == 0) { // for it to be a leaf
			System.out.print(node.data + " ");
			return true;
		}
		boolean res = false;
		res = res || pathSum_I(node.l, tar - node.data); // this is done to save the calls
		res = res || pathSum_I(node.r, tar - node.data); //
		if (res) {
			System.out.print(node.data + " ");
		}
		return res;
	}

	public static ArrayList<ArrayList<Integer>> pathSum_II_01(Node node, int tar) {
		if (node == null) {
			return null;
		}
		if (node.l == null && node.r == null && tar - node.data == 0) {
			ArrayList<Integer> inner = new ArrayList<>();
			inner.add(node.data);
			ArrayList<ArrayList<Integer>> outer = new ArrayList<>();
			outer.add(inner);
			return outer;
		}

		ArrayList<ArrayList<Integer>> finalAns = new ArrayList<>();
		ArrayList<ArrayList<Integer>> left = pathSum_II_01(node.l, tar - node.data);
		if (left != null) {
			for (ArrayList<Integer> inner : left) {
				inner.add(0, node.data);
				finalAns.add(inner);
			}
		}
		ArrayList<ArrayList<Integer>> right = pathSum_II_01(node.r, tar - node.data);
		if (right != null) {
			for (ArrayList<Integer> inner : right) {
				inner.add(0, node.data);
				finalAns.add(inner);
			}
		}

		return finalAns;
	}

	public static void pathSum_II_02(Node node, int tar, ArrayList<Integer> inner,
			ArrayList<ArrayList<Integer>> finalAns) {
		if (node == null)
			return;
		if (node.l == null && node.r == null && tar - node.data == 0) {
			ArrayList<Integer> onePath = new ArrayList<>(inner);
			onePath.add(node.data);
			finalAns.add(onePath);
			return;
		}
		inner.add(node.data);
		pathSum_II_02(node.l, tar - node.data, inner, finalAns);
		pathSum_II_02(node.r, tar - node.data, inner, finalAns);
		inner.remove(inner.size() - 1);
	}

	public static int pathSum_III(Node node, int prefixSum, int tar, HashMap<Integer, Integer> map) {
		if (node == null)
			return 0;
		prefixSum += node.data;

		int count = map.getOrDefault(prefixSum - tar, 0);
		map.put(prefixSum, map.getOrDefault(prefixSum, 0) + 1);

		count += pathSum_III(node.l, prefixSum, tar, map);
		count += pathSum_III(node.r, prefixSum, tar, map);

		if (map.get(prefixSum) == 1) {
			map.remove(prefixSum);
		} else {
			map.put(prefixSum, map.get(prefixSum) - 1);
		}

		return count;
	}
	// ===========================Max SUM FROM ONE LEAF TO
	// ANOTHER==========================//
	// public static int maxLeafSum(Node node) {
	// if(node==null){
	// return 0;
	// }
	// int leftSum=maxLeafSum(node.l);
	// int rightSum=maxLeafSum(node.r);

	// }

	// ========================Two nodes swapped in BST=========================//
	// static Node previous=null;
	// static Node n1=null;
	// static Node n2=null;
	// public static void reconstruct(){
	// reconstruct(root);
	// Node temp=new Node(0,null,null);
	// temp.data=n1.data;
	// n1.data=n2.data;
	// n2.data=temp.data;
	// }
	// public static void reconstruct(Node node){
	// if(node==null) return;
	// reconstruct(node.l);
	// previous=node;
	// if(previous.data>node.data){
	// n2=node;
	// if(n1==null)
	// n1=previous;
	// }
	// reconstruct(node.r);
	// }
	// =================construcy bst using pre===========================//

	// static int size=0;
	// public static Node construct_BST(int[] arr){
	// if(size==arr.length) return null;
	// Node nnode=new Node(arr[size++],null,null);
	// Node left=construct_BST(arr);
	// Node right=construct_BST(arr);
	// if(left.data<nnode.data){
	// nnode.l=left;
	// }else{
	// nnode.r=left;
	// }
	// if(right.data>nnode.data){
	// nnode.r=right;
	// }else{
	// nnode.l=right;
	// }
	// return nnode;
	// }

	// ===========================================Bst USING INORDER,add new
	// node,delete a node======================================//
	public static Node constructUsingIn(int[] arr, int lb, int ub) {
		if (ub < lb) {
			return null;
		}

		int mid = (lb + ub) / 2;
		Node node = new Node(arr[mid], null, null);
		node.l = constructUsingIn(arr, lb, mid - 1);
		node.r = constructUsingIn(arr, mid + 1, ub);

		return node;
	}
	// public static Node findInBst(Node node,int data){
	// if(node.data==data){
	// return node;
	// }
	// Node ans=null;
	// ans=findInBst(node.l, data);
	// if(ans){
	// return ans;
	// }
	// ans=findInBst(node.r, data);
	// return ans;
	// }
	// public static int maxNode=-(1e8);
	// public static Node findMax(Node node) {

	// }
	// public static Node removeNode(Node node,int data){
	// if(node.data==data){
	// if(node.l==null && node.r==null){
	// return null;
	// }else if(node.l==null || node.r==null){
	// return node.l==null?node.l:node.r;
	// }else if(node.l!=null && node.r!=null){
	// // Node max=
	// }
	// }
	// }

	// ================================BST LCA================================//
	public static Node BSTLca(Node node, int n1, int n2) {
		if (node == null) {
			return null;
		}
		Node ans = new Node();
		if (n1 > node.data) {
			ans = BSTLca(node.r, n1, n2);
		} else if (n2 < node.data) {
			ans = BSTLca(node.r, n1, n2);
		} else if (n1 <= node.data && n2 >= node.data) {
			return node;
		}
		return ans;
	}

	static int leftWidth = 0;
	static int rightWidth = 0;
	static int Width = 0;

	public static void maxWidth(Node node, int w) {
		if (node == null) {
			if (w + 1 < leftWidth) {
				leftWidth = w + 1;
				return;
			}
			if (w - 1 > rightWidth) {
				rightWidth = w - 1;
				return;
			}
			return;
		}
		maxWidth(node.l, w - 1);
		maxWidth(node.r, w + 1);
	}

	public static void printDiagonalSum(Node node, int diag, int[] diagSum) {

		if (diag == -1) {
			System.out.println(diagSum.length);
			for (int i = ((diagSum.length) - 1); i >= 0; i--) {
				System.out.println(diagSum[i]);
			}
			return;
		}
		diagSum[diag] += node.data;
		printDiagonalSum(node.l, diag - 1, diagSum);
		if (node.r != null) {
			printDiagonalSum(node.r, diag, diagSum);
		}
	}
	// public static int[] verticalSum(Node node) {

	// }

	// =============================Iterative pre,post,in====================//
	public static class Tpair {
		Node node;
		boolean sd, ld, rd;

		Tpair(Node node) {
			this.node = node;
		}
	}

	public static void traverse(Node node) {
		Stack<Tpair> st = new Stack<>();
		st.push(new Tpair(node));
		while (st.size() != 0) {
			Tpair tpair = st.peek();
			if (!tpair.sd) {
				tpair.sd = true;
				System.out.print(tpair.node.data + " ");
			} else if (!tpair.ld) {
				tpair.ld = true;
				st.push(new Tpair(tpair.node.l));
			} else if (!tpair.rd) {
				tpair.rd = true;
				st.push(new Tpair(tpair.node.r));
			} else {
				st.pop();
			}
		}
	}

	public static void main(String[] args) {
		Btree b = new Btree();
		// int[] arr = { 10, 20, 30, 40, 50, 60, 80, -1, -1, -1, 70, 90, -1, 100, -1, -1, -1 };
		// int arr[]={1,3,-1,2,-1,-1,-1};
		int arr[]={50,25,20,30,75,65};
		// int[] arr={1 ,2 ,3 ,4 ,5 ,6 ,7 ,-1, -1, -1 ,-1 ,-1 ,8 ,-1, 9};

		b.construct(arr,0);
		treeToDLL(root);
		Node temp=head_;
		while(temp!=null){
			System.out.print(temp.data+" -> ");
			temp=temp.l;
		}
		System.out.println();
		// display(root);
	}
}