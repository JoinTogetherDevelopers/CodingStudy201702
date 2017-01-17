# author : huklee
# solution for 34 cards problem

# Simplied solution
def solve_simple(input):
    i1, i2 = 1, 1
    for i in reversed(range(len(input) - 1)):
        if (input[i]*10 + input[i+1] <= 34):
            i1, i2 = i2, i1 + i2
        else:
            i1, i2 = i2, i2
    return i2

# DP-similar approach
def solve_DP(input):
    d = {'0':1, '1':1, '':1}
    input_ = []
    # 01. Convert the code into binary combination
    for i in range(len(input) - 1):
        if (input[i]*10 + input[i+1] <= 34):
            input_.append('1')
        else:
            input_.append('0')
    input_.append('0')
    
    # 02. DP-similar approach
    for i in reversed(range(len(input_) - 1)):
        if (input_[i] == '1'):
            d["".join(input_[i:])] = d["".join(input_[i + 1:])] + d["".join(input_[i + 2:])]
        else:
            d["".join(input_[i:])] = d["".join(input_[i + 1:])]
    return d["".join(input_)]

def main():
    _input = [1,7,1,2,1]
    print (solve_simple(_input))
    print (solve_DP(_input))
    
main()
