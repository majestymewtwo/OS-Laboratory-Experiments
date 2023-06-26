choice=0
while [ $choice -ne 4 ]; do
    echo " "
    echo "********Menu**********"
    echo "1 - Display list of files"
    echo "2 - Delete files from directory"
    echo "3 - Append a file"
    echo "4 - Exit"
    read choice 

    case $choice in
        1) 
            ls -l;;
        2) 
            echo "Enter the filename"
            read file
            rm $file;;
        3)
            echo "Enter the filename"
            read file
            echo "Enter data to be appended (CTRL + D when done)"
            cat >> $file ;;
        4)
            echo "Thank you for using our CLI menu"
    esac
done