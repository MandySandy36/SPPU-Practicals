import socket

def dns_lookup():
    print("DNS Lookup Tool")
    print("1. Convert URL to IP")
    print("2. Convert IP to URL")
    
    choice = input("Enter your choice (1 or 2): ")
    
    if choice == '1':
        # URL to IP lookup
        url = input("Enter the URL (e.g., www.example.com): ")
        try:
            ip = socket.gethostbyname(url)
            print("The IP address of ",url," is ",ip)
        except socket.gaierror:
            print("Invalid URL or DNS lookup failed.")
    
    elif choice == '2':
        # IP to URL lookup (reverse DNS)
        ip = input("Enter the IP address (e.g., 93.184.216.34): ")
        try:
            domain = socket.gethostbyaddr(ip)
            print("The domain name associated with IP",ip,"is",domain[0])
        except socket.herror:
            print("No domain associated with this IP address or lookup failed.")
    
    else:
        print("Invalid choice. Please select either 1 or 2.")

if __name__ == "__main__":
    dns_lookup()
