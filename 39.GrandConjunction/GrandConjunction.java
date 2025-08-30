class DoublyListNode {
    int val;
    DoublyListNode prev;
    DoublyListNode next;

    public DoublyListNode(int val) {
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

public class GrandConjunction {
    public DoublyListNode rotate(DoublyListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        DoublyListNode tail = head;
        int n = 1;
        while (tail.next != null) {
            tail = tail.next;
            n++;
        }

        int effectiveK = k % n;
        if (effectiveK == 0) {
            return head;
        }

        tail.next = head;
        head.prev = tail;

        DoublyListNode newTail = head;
        for (int i = 0; i < n - effectiveK - 1; i++) {
            newTail = newTail.next;
        }

        DoublyListNode newHead = newTail.next;

        newTail.next = null;
        newHead.prev = null;

        return newHead;
    }
}
