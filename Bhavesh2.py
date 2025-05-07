class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]  # Initialize with empty chains

    def hash_function(self, key):
        return key % self.size  # Simple modulo-based hash function

    def insert(self, key):
        index = self.hash_function(key)
        self.table[index].append(key)  # Insert key into the appropriate list

    def search(self, key):
        index = self.hash_function(key)
        return key in self.table[index]  # Return True if key is found

    def delete(self, key):
        index = self.hash_function(key)
        if key in self.table[index]:
            self.table[index].remove(key)
            return True
        return False

    def display(self):
        print("Hash Table:")
        for i, chain in enumerate(self.table):
            print(f"Index {i}: {chain}")

# Example usage
if __name__ == "__main__":
    ht = HashTable(10)  # Create a hash table of size 10

    # Insert keys
    ht.insert(15)
    ht.insert(25)
    ht.insert(35)
    ht.insert(10)

    # Display the hash table
    ht.display()

    # Search for a key
    key = 25
    print(f"\nSearch for {key}: {'Found' if ht.search(key) else 'Not Found'}")

    # Delete a key
    key = 35
    print(f"Delete {key}: {'Success' if ht.delete(key) else 'Failure'}")

    # Display the hash table after deletion
    print("\nHash Table after deletion:")
    ht.display()
