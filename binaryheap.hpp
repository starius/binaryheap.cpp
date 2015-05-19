#include <assert.h>
#include <map>
#include <vector>
#include <algorithm>

// min heap
template < typename Value, typename Payload,
         typename Cmp = std::less<Value> >
class BinaryHeap {
public:
    BinaryHeap(const Cmp& cmp = Cmp()):
        less_(cmp) {
    }

    void insert(const Payload& payload, const Value& value) {
        assert(reverse_.find(payload) == reverse_.end());
        int index = size();
        values_.push_back(value);
        payloads_.push_back(payload);
        reverse_[payload] = index;
        bubbleUp(index);
    }

    void top(Payload& payload, Value& value) const {
        value = values_[0];
        payload = payloads_[0];
    }

    void update(const Payload& payload, const Value& value) {
        updatePos(reverse_[payload], value);
    }

    Value valueByPayload(const Payload& payload) const {
        return values_[reverse_.at(payload)];
    }

    bool empty() const {
        return values_.empty();
    }

    int size() const {
        return values_.size();
    }

    void pop() {
        removePos(0);
    }

    void remove(const Payload& payload) {
        int index = reverse_[payload];
        removePos(index);
    }

    void check() const {
        assert(payloads_.size() == values_.size());
        assert(payloads_.size() == reverse_.size());
        // binary heap order of elements
        for (int index = 1; index < size(); index++) {
            int parent = parentOf(index);
            assert(!less(index, parent));
        }
        // consistence of reverse_ and payloads_
        for (int index = 0; index < size(); index++) {
            const Payload& payload = payloads_[index];
            assert(reverse_.at(payload) == index);
        }

    }

private:
    Cmp less_;
    std::vector<Value> values_;
    std::vector<Payload> payloads_;
    typedef std::map<Payload, int> Reverse;
    Reverse reverse_;

    bool less(int i1, int i2) const {
        return less_(values_[i1], values_[i2]);
    }

    static int parentOf(int index) {
        return (index - 1) / 2;
    }

    static int leftChildOf(int index) {
        return index * 2 + 1;
    }

    static int rightChildOf(int index) {
        return index * 2 + 2;
    }

    void bubbleUp(int index) {
        while (index > 0) {
            int parent = parentOf(index);
            if (less(index, parent)) {
                swap(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }

    void sinkDown(int index) {
        while (true) {
            int min_index = index;
            int left = leftChildOf(index);
            int right = rightChildOf(index);
            if (left < size() && less(left, min_index)) {
                min_index = left;
            }
            if (right < size() && less(right, min_index)) {
                min_index = right;
            }
            if (min_index == index) {
                break;
            }
            swap(index, min_index);
            index = min_index;
        }
    }

    void updatePos(int index, const Value& value) {
        values_[index] = value;
        bubbleUp(index);
        sinkDown(index);
    }

    void removePos(int index) {
        assert(index >= 0 && index < size());
        Payload payload = payloads_[index];
        int last = size() - 1;
        if (index < last) {
            swap(index, last);
            values_.resize(last);
            payloads_.resize(last);
            bubbleUp(index);
            sinkDown(index);
        } else {
            values_.resize(last);
            payloads_.resize(last);
        }
        reverse_.erase(payload);
    }

    void swap(int i1, int i2) {
        Payload p1 = payloads_[i1];
        Payload p2 = payloads_[i2];
        reverse_[p1] = i2;
        reverse_[p2] = i1;
        payloads_[i1] = p2;
        payloads_[i2] = p1;
        //
        Value v1 = values_[i1];
        Value v2 = values_[i2];
        values_[i1] = v2;
        values_[i2] = v1;
    }
};
