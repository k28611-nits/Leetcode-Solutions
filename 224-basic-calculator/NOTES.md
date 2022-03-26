This is a very good stacks problem , we are given an expression in form of string with
chars as [nums , '(' , ')' , '+' , '-' , ' ']
​
Note : we can totally ignore ' ' and  '+'.
Logic:
what we are going to do is very simple ,
first intilaize two vars , sum and sign
sum = 0
sign = +1
traverse the string:
if(ch is digit)
num = get_full_num; // may be multidigit
add it to sum , sum += (num * sign)
reset sign to +1
else if(ch is '(')
save current state of sum and sign in stack
reset sum and sign
else if(ch is ')')
sum = val_at_top + (sign_at_top * sum)
pop;
else if(ch is '-')
toggle sign
the use of sum and sign are to evaluate current expression inside a () braces or completely outside
stack is used to store the state of sum and sign take example
1 + 2 + 3 - (5 + 6) => 6 - (5 + 6)
when we encounter '(' saving state means
stack will store pair(6 , -) and first calculate (5 + 6)
once (5 + 6) is calculated which is 11
pop from stack => sum = (6 + (sum * -1)) = (6 + (11 * -1)) = -5 ans