<?php
//////////////////////////////////////////////////////
// FILE: getAuthor.php
// AUTHOR: Doug MacClure
// ZID: z0125061
// CSCI466-1
// Purpose: Get user information from html form, query database
// via mysql query, and send results back to html form in table
// form.
/////////////////////////////////////////////////////





//Initialize variables for database
$hostName="student";
$username="z0125061";
$password="2%dSZ1gH54#2dz_1o8";
$db="z0125061";

//Initialize variables for commands from html form
$AuthF = $_POST['AuthorFirst'];
$AuthL = $_POST['AuthorLast'];

//Establish connection to database
$conn=mysql_connect($hostName, $username, $password);

//check if connection to server failed
if(!$conn)
	{

	die('Unable to connect:'. mysql_error());
	
	}
//select database
$selectedDB = mysql_select_db($db,$conn);

//check if we could access database
if (!$selectedDB) 
	{

	die("Can't access: ". $db . mysql_error());

	}

//Build SQL statement
$sql = "SELECT * FROM Book,Author WHERE Author.AuthorFirst= ". $AuthF" AND Author.AuthLast= " 
	. $AuthL . " ORDER BY Book.Title";

//Execute SQL statement
$result = mysql_query($sql, $conn);
	
	//check if statement worked
	if(!$result)

		{

		die("Can't execute sql statement:" .mysql_error());


		}

//display Book information in html

$numrows= mysql_num_rows($result);

echo '<table>';
echo '<tr>';
echo '<th>Book Code</th>';
echo '<th>Title</th>';
echo '<th>Publisher Code</th>';
echo '<th>Type</th>';
echo '<th>Price</th>';
echo '<th>Paperback</th>';
echo '</tr>';


for($i = 0; $i <$numrows; $i++)

	{

	echo '<tr>';
	$row=mysql_fetch_array($result);
	echo '<td>', ($row[0]),'</td>';
	echo '<td>', ($row[1]),'</td>';
	echo '<td>', ($row[2]),'</td>';
	echo '<td>', ($row[3]),'</td>';
	echo '<td>', ($row[4]),'</td>';
	echo '<td>', ($row[5]),'</td>';
	echo '</tr>';
	}

echo '</table>';


//Now, we build another sql statement, that checks the number of books the Author has written

$sql= "COUNT(Book.Title) FROM Author,Book WHERE Author.AuthorFirst = " . $AuthF 
	. " AND Author.AuthorLast = " . $AuthL;

//Execute SQL statement
$result = mysql_query($sql, $conn);
	
	//check if statement worked
	if(!$result)

		{

		die("Can't execute sql statement:" .mysql_error());


		}

//display Book information in html

$numrows= mysql_num_rows($result);
echo '<p>Number of books author has written owned by Henry Books: ';
echo ($row[0]), '</p>';
?>
