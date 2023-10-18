class ConvertToBinary:

    def __init__(self):
        pass

    def convert(self, n):
        x = 1024  # 10-bit (2¹⁰)

        while x > 0:
            if n >= x:
                n %= x
                print(1, end="")
                  
            else:
                print(0, end="")
                
            x >>= 1

        # print("");

    def main(self):
        for n in range(1, 5000000):
            self.convert(n)

if __name__ == "__main__":
    my_instance = ConvertToBinary()
    my_instance.main()
