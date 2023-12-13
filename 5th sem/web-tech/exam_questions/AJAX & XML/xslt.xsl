<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<body>
  <h2>Student Details</h2>
  <table border="1">
  <tr bgcolor="#9acd32">
    <th>Name</th>
    <th>Roll No</th>
    <th>Class</th>
    <th>Address</th>
  </tr>

  <xsl:for-each select="student/studentinfo">
  <tr>
    <td><xsl:value-of select="name"/></td>
    <td><xsl:value-of select="rollno"/></td>
    <td><xsl:value-of select="class"/></td>
    <td><xsl:value-of select="address"/></td>
  </tr>
  </xsl:for-each>
  </table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

