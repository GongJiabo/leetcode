// from leetcode:
// https://leetcode-cn.com/problems/flatten-nested-list-iterator/solution/c-zong-he-ge-lu-da-lao-de-da-an-by-fxxuuu/
//1. 构造时仅仅扒一层皮就 逆向 堆入栈中，在用户调用 hasNext 时才做深入扒皮搜索。
//   这种做法比较时间均衡，如果用户搞了一个很长的列表，然后就取前边几个元素就不用了，那这种实现要高效的多。
class NestedIterator {
private:
  stack<NestedInteger> st;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
      st.push(*iter);
    }
  }

  int next() {
    auto t = st.top();
    st.pop();
    return t.getInteger();
  }

  bool hasNext() {
    while (!st.empty()) {
      auto cur = st.top();
      if (cur.isInteger()) return true;
      st.pop();
      auto curList = cur.getList();
      for (auto iter = curList.rbegin(); iter != curList.rend(); iter++) {
        st.push(*iter);
      }
    }
    return false;
  }
};

//2. 构造时扒皮抽骨到单个数字再 push 到栈里。这样预处理很慢，但是调用时很快。有点头重脚轻。
class NestedIterator {
private:
  stack<NestedInteger> st;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
      parseData(*iter);
    }
  }
  void parseData(NestedInteger item) {
    if (item.isInteger()) {
      st.push(item);
    } else {
      auto list = item.getList();
      for (auto iter = list.rbegin(); iter != list.rend(); iter++) {
        parseData(*iter);
      }
    }
  }

  int next() {
    auto t = st.top();
    st.pop();
    return t.getInteger();
  }

  bool hasNext() {
    if (st.empty()) return false;
    return true;
  }
};

//3. 不用栈，用 vector 来做也可以。只是存储的时候不再是从尾到头而是从头到尾。
class NestedIterator {
private:
  vector<int> v;
  int ind = 0;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto iter = nestedList.begin(); iter != nestedList.end(); iter++) {
      parseData(*iter);
    }
  }
  void parseData(NestedInteger item) {
    if (item.isInteger()) {
      v.push_back(item.getInteger());
    } else {
      auto list = item.getList();
      for (auto iter = list.begin(); iter != list.end(); iter++) {
        parseData(*iter);
      }
    }
  }

  int next() {
    return v[ind++];
  }

  bool hasNext() {
    if (ind >= v.size()) return false;
    return true;
  }
};