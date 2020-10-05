#Parameteren $1 er filnavn m. katalog
#Beregn katalognavn utfra filnavn`
#JPGDIR=`dirname $1`/jpg
JPGDIR=`dirname $1`
if (echo  $JPGDIR | grep -q .*/jpg ); then echo `basename $1`' is already in jpg dir'; exit ; fi
#Opprett hvis den ikke fins fra før
if [ ! -d $JPGDIR/jpg ] ; then mkdir $JPGDIR/jpg ; fi
#Flytt filen
mv $1 $JPGDIR/jpg
echo 'Moved '`basename $1`' into jpg dir'
