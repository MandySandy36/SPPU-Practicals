class HashFunction:
    def __init__(self):
        self.h = [{'key': -1, 'name': 'NULL'} for _ in range(10)]

    def insert(self):
        cnt = 0
        while cnt < 10:
            k = int(input("\n\tEnter a Key: "))
            n = input("\n\tEnter a Value: ")
            hi = k % 10  # hash function
            if self.h[hi]['key'] == -1:
                self.h[hi] = {'key': k, 'name': n}
            else:
                temp = self.h[hi]['key']
                ntemp = self.h[hi]['name']
                self.h[hi] = {'key': k, 'name': n}
                flag = 0
                for i in range(hi + 1, 10):
                    if self.h[i]['key'] == -1:
                        self.h[i] = {'key': temp, 'name': ntemp}
                        flag = 1
                        break
                for i in range(hi):
                    if self.h[i]['key'] == -1 and flag == 0:
                        self.h[i] = {'key': temp, 'name': ntemp}
                        break
            cnt += 1
            ans = input("\n\t..... Do You Want to Insert More Key: y/n=")
            if ans.lower() != 'y':
                break

    def display(self):
        print("\n\t\tKey\t\tName")
        for i, item in enumerate(self.h):
            print("\n\th[{}]{}\t\t{}".format(i, item['key'], item['name']))

    def find(self, k):
        for i, item in enumerate(self.h):
            if item['key'] == k:
                print("\n\t{} is Found at {} Location With Name {}".format(item['key'], i, item['name']))
                return i
        return -1

    def delete(self, k):
        index = self.find(k)
        if index == -1:
            print("\n\tKey Not Found")
        else:
            self.h[index] = {'key': -1, 'name': 'NULL'}
            print("\n\tKey is Deleted")


if __name__ == "__main__":
    obj = HashFunction()
    while True:
        print("\n\t***** Dictionary (ADT) *****")
        print("\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit")
        ch = int(input("\n\t..... Enter Your Choice: "))
        if ch == 1:
            obj.insert()
        elif ch == 2:
            obj.display()
        elif ch == 3:
            k = int(input("\n\tEnter a Key Which You Want to Search: "))
            obj.find(k)
        elif ch == 4:
            k = int(input("\n\tEnter a Key Which You Want to Delete: "))
            obj.delete(k)
        elif ch == 5:
            break
        ans = input("\n\t..... Do You Want to Continue in Main Menu: y/n= ")
        if ans.lower() != 'y':
            break