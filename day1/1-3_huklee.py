# author : huklee

# Simplied solution
def solve(input):
	return  ".join(reversed(a.split(" ")))	

def main():
    _input = "asd 123 qwe asd 456" 
    print (solve(_input))
    
main()
