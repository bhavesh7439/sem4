 
class TelephoneDirectory:
    """A simple telephone directory implemented using hash tables with linear probing. 
    Supports storing and retrieving names and phone numbers.
    """

    def __init__(self, size):
        """Initialize the telephone directory with a given size. 
        Each slot in the directory is initially set to None.
        """
        self.size = size
        self.directory = [None] * size

    def hash_function(self, key):
        """Hash function to calculate an index from a key. 
        The key is the sum of the ASCII values of the characters in the name.
        """
        return key % self.size

    def insert(self, name, number):
        """Insert a name and phone number into the directory. 
        Resolves collisions using linear probing.
        """
        key = sum(ord(char) for char in name.lower())  # Convert to lowercase for uniformity
        index = self.hash_function(key)

        # Linear probing to find the next available slot
        for i in range(self.size):
            new_index = (index + i) % self.size
            if self.directory[new_index] is None:  # Found an empty slot
                self.directory[new_index] = (name, number)
                return
        print("Directory is full! Cannot insert new entry.")

    def search(self, name):
        """Search for a phone number by name. Returns the number if found, otherwise None."""
        key = sum(ord(char) for char in name.lower())
        index = self.hash_function(key)

        # Linear probing to search for the name
        for i in range(self.size):
            new_index = (index + i) % self.size
            if self.directory[new_index] is None:
                return None
            if self.directory[new_index][0].lower() == name.lower():
                return self.directory[new_index][1]
        return None

    def display(self):
        """Display the entire telephone directory, showing each index and entry."""
        print("\nTelephone Directory:")
        for i, entry in enumerate(self.directory):
            if entry:
                print(f"Index {i}: {entry}")
            else:
                print(f"Index {i}: Empty")

# Example Usage
if __name__ == "__main__":
    # Create a directory with 10 slots
    directory = TelephoneDirectory(10)

    # Insert names and phone numbers
    directory.insert("John", "1234567890")
    directory.insert("Alice", "2345678901")
    directory.insert("Bob", "3456789012")
    directory.insert("Eve", "4567890123")
    directory.insert("Charlie", "5678901234")

    # Display the directory
    directory.display()

    # Search for a phone number by name
    names_to_search = ["Alice", "Bob", "David"]  # David is not in the directory
    for name in names_to_search:
        result = directory.search(name)
        if result:
            print(f"Phone number for {name}: {result}")
        else:
            print(f"{name} not found in the directory.")
