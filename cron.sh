echo `date`
cd /home/triten/Projects/DNA
git add .
git commit -m "chore: `date` solutions"
git push origin main
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
fi
