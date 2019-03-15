package main

import(
	"fmt"
	"net"
	"os"
)


func checkErr(err error){
	if err != nil{
		fmt.Fprintf(os.Stderr, "Fatal error: %s", err.Error())
		os.Exit(1)
	}
}


func handleClient(conn net.Conn){
	defer conn.Close()
	var buf [1024]byte
	for {
		n, err := conn.Read(buf[0:])
		if err != nil{
			return
		}
		rAddr := conn.RemoteAddr()
		fmt.Println("Receive from client",rAddr.String(),string(buf[0:n]))
		_, err = conn.Write([]byte("Welcome client!"))
		if err !=nil{
			return
		}
	}

}



func main(){
	port := ":8080"
	tcpAddr, err := net.ResolveTCPAddr("tcp4",port)
	checkErr(err)
	listener, err := net.ListenTCP("tcp",tcpAddr)
	checkErr(err)
	for{
		conn, err := listener.Accept()
		if err != nil{
			continue
		}
		go handleClient(conn)
	}

}
