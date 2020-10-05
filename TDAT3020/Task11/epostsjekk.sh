#ll!/bin/bash

# MX info:
echo ""
dig=`dig mx $1 +short | cut -c 3-`
echo "MX maskiner fra: $1:"
for address in $dig;
do
  addressIPv4=`nslookup $address | grep 'Address:' | tail -n 2 | head -n 1 | cut -d ' ' -f 2`
  addressIPv6=`nslookup $address | grep 'Address:' | tail -n 1 | cut -d ' ' -f 2`
  echo "- Domene: ${address%?}, IPv4: $addressIPv4, IPv6: $addressIPv6"
done
echo ""

# SPF info
echo "SPF info:"

find_ip() {
    
    nslookup -type=txt $1 | grep v=spf1 | tr ' ' '\n' | grep ip
    SPF_include=`nslookup -type=txt $1 | grep v=spf1 | tr ' ' '\n' | grep include | cut -d ':' -f 2`

    for domain in $SPF_include; do
        printf "Running spf_include on $domain\n"
        find_ip $domain
    done

    SPF_redirect=`nslookup -type=txt $1 | grep v=spf1 | tr ' ' '\n' | grep redirect | cut -d '=' -f 3`

    for domain in $SPF_redirect; do
        printf "Running spf_redirect on $domain\n"
        find_ip $domain
    done
}

find_ip $1
