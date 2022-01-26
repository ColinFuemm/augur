/*
##################### Question 1 #####################
Verification will come through checking each property.
bool rb_tree_check(T) {
  if sub_check(T) is -1:
    return false
  else return true
}
sub_check(T) { 
  if T.color is red or black: //Property 1
    if T is red:
      if T is root: //Property 2
        return -1
      if T is leaf: //Property 3
        return -1
      if T.left or T.right are red: //Property 4
        return -1
    else:
      blackCount = 1
    right_blacks = sub_Check(T.right)
    left_blacks = sub_Check(T.left)

    if right_blacks or left_blacks == -1:
      return -1
    else:
      if right_blacks == left_blacks: //Property 5
        return right_blacks + blackCount
      else return -1
  else return -1
}

##################### Question 2 #####################
1. invalid by property 3 & 5.
2. invalid by property 3.
3. valid
4. valid

##################### Question 3 #####################
Max Height: 5    [Black] (Red)
              [  6  ] Black Height: 3
              /     \
          ( 3 )     ( 9 )
          /   \     /   \ 
        [2]   [5] [8]   [11]
        /     /   /     /  \
      [1]   [4] [7]   [10] (13)
                           /  \
                         [12][14]
##################### Question 4 #####################
inversion_Count(Array A)
  OSTree T
  for i < n
    Insert(Tree t, A[i])
  Stack S
  count = 0
  while stack not empty && cursor not NULL
    if cursor not NULL
        S->push(cursor)
        left<-cursor
      else
        cursor = S->head
        count += (OS-Rank(t, cursor) - 1)
        S.pop()
        right<-cursor
  return count
    

##################### Question 5 #####################
interval_list(tree t, interval i) 
  if i.low or i.high between t.low and t.high
    overlap true
  else if t.low and t.high between i.low and i.high
    overlap true
  if t->left not NULL
    interval_list(t->left, i)
  if t->right not NULL
    interval_list(t->right, i)
  if overlap:
    print '[t->low, t->high]'
*/