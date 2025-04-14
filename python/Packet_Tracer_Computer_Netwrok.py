# type: ignore
from scapy.all import *  
pcap = rdpcap("trace1.pcap")

print("Total: " + str(len(pcap)))

spcap = str(pcap)
print(spcap)
x = spcap.split(" ")
pcap_array = []
for i in x:
    pcap_array.append(i.split(":"))
lenPacp= len(pcap)
LENTCP=  pcap_array[1][1]
LENUDP= pcap_array[2][1]
print("TCP: ", (int(LENTCP)/len(pcap) * 100), "UDP: ", (int(LENUDP)/len(pcap) * 100))

for pkt in pcap: 
    print(pkt.show());

