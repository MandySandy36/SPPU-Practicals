class Client:
    def __init__(self, name, phone_number):
        self.name = name
        self.phone_number = phone_number

class HashTable:
    def __init__(self, max_size=10):
        self.max_size = max_size
        self.table = [None] * max_size

    def insert(self, client):
        hash_value = self.hash(client.phone_number)
        if self.table[hash_value] is None:
            self.table[hash_value] = client
        else:
            i = (hash_value + 1) % self.max_size
            while i != hash_value:
                if self.table[i] is None:
                    self.table[i] = client
                    break
                i = (i + 1) % self.max_size

    def display(self):
        print("------------------------------------")
        print("Srno\tPhone number")
        print("------------------------------------")
        for i in range(self.max_size):
            if self.table[i] is not None:
                print(f"{i}\t{self.table[i].phone_number}")
        print("------------------------------------")

    def search(self, phone_number):
        print("Enter Phone number to be searched:")
        phone_number = int(input())
        for i in range(self.max_size):
            if self.table[i] is not None and self.table[i].phone_number == phone_number:
                print(f"Phone Number Found at position {i}")
                return
        print("Phone Number Not Found")

    def delete(self, phone_number):
        print("Enter phone number to be deleted:")
        phone_number = int(input())
        for i in range(self.max_size):
            if self.table[i] is not None and self.table[i].phone_number == phone_number:
                self.table[i] = None
                print("Phone number found and deleted")
                return
        print("Phone number not found")

    def hash(self, key):
        return key % self.max_size

def main():
    h = HashTable()
    while True:
        print("\n---------------LIST---------------\n")
        print("1. INSERT\n2. DISPLAY\n3. SEARCH\n4. DELETE\n5. EXIT\n")
        iCh = int(input("Enter your choice: "))

        if iCh == 1:
            name = input("Enter name: ")
            phone_number = int(input("Enter phone number: "))
            client = Client(name, phone_number)
            h.insert(client)
        elif iCh == 2:
            h.display()
        elif iCh == 3:
            h.search(None)
        elif iCh == 4:
            h.delete(None)
        elif iCh == 5:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()