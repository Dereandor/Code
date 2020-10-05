[dereandor@manjaro Task11]$ ./epostsjekk.sh vg.no

MX maskiner fra: vg.no:
- Domene: ALT2.ASPMX.L.GOOGLE.COM, IPv4: 74.125.28.27, IPv6: 2607:f8b0:400e:c04::1a
- Domene: ALT1.ASPMX.L.GOOGLE.COM, IPv4: 108.177.97.27, IPv6: 2404:6800:4008:c00::1b
- Domene: ALT4.ASPMX.L.GOOGLE.COM, IPv4: 209.85.146.26, IPv6: 2607:f8b0:4001:c1f::1b
- Domene: ALT3.ASPMX.L.GOOGLE.COM, IPv4: 142.250.28.27, IPv6: 2607:f8b0:4003:c1c::1a
- Domene: ASPMX.L.GOOGLE.COM, IPv4: 173.194.222.26, IPv6: 2a00:1450:4010:c06::1b

SPF info:
ip4:84.34.190.160/32
ip4:195.88.54.12
ip4:87.238.36.194
ip6:2a02:c0:20c:1::194
ip4:212.237.201.64/27
Running spf_include on _spf.schibsted-it.no
ip4:80.91.34.51
ip4:80.91.34.67
ip4:80.91.34.53
ip4:80.91.34.179
ip4:80.91.32.58
Running spf_include on _spf.google.com
Running spf_include on _netblocks.google.com
ip4:35.190.247.0/24
ip4:64.233.160.0/19
ip4:66.102.0.0/20
ip4:66.249.80.0/20
ip4:72.14.192.0/18
ip4:74.125.0.0/16
ip4:108.177.8.0/21
ip4:173.194.0.0/16
ip4:209.85.128.0/17
ip4:216.58.192.0/19
ip4:216.239.32.0/19
Running spf_include on _netblocks2.google.com
ip6:2001:4860:4000::/36
ip6:2404:6800:4000::/36
ip6:2607:f8b0:4000::/36
ip6:2800:3f0:4000::/36
ip6:2a00:1450:4000::/36
ip6:2c0f:fb50:4000::/36
Running spf_include on _netblocks3.google.com
ip4:172.217.0.0/19
ip4:172.217.32.0/20
ip4:172.217.128.0/19
ip4:172.217.160.0/20
ip4:172.217.192.0/19
ip4:172.253.56.0/21
ip4:172.253.112.0/20
ip4:108.177.96.0/19
ip4:35.191.0.0/16
ip4:130.211.0.0/22
Running spf_include on mail.zendesk.com
ip4:192.161.144.0/20
ip4:185.12.80.0/22
ip4:188.172.128.0/20
ip4:216.198.0.0/18
[dereandor@manjaro Task11]$ ./epostsjekk.sh ibm.com

MX maskiner fra: ibm.com:
- Domene: mx0b-001b2d01.pphosted.com, IPv4: Address:    192.168.20.1#53, IPv6: 148.163.158.5
- Domene: mx0a-001b2d01.pphosted.com, IPv4: Address:    192.168.20.1#53, IPv6: 148.163.156.1

SPF info:
ip4:148.163.158.5
ip4:148.163.156.1
ip4:67.231.145.127
ip4:67.231.153.87
ip4:168.245.101.145
Running spf_include on _spf.google.com
Running spf_include on _netblocks.google.com
ip4:35.190.247.0/24
ip4:64.233.160.0/19
ip4:66.102.0.0/20
ip4:66.249.80.0/20
ip4:72.14.192.0/18
ip4:74.125.0.0/16
ip4:108.177.8.0/21
ip4:173.194.0.0/16
ip4:209.85.128.0/17
ip4:216.58.192.0/19
ip4:216.239.32.0/19
Running spf_include on _netblocks2.google.com
ip6:2001:4860:4000::/36
ip6:2404:6800:4000::/36
ip6:2607:f8b0:4000::/36
ip6:2800:3f0:4000::/36
ip6:2a00:1450:4000::/36
ip6:2c0f:fb50:4000::/36
Running spf_include on _netblocks3.google.com
ip4:172.217.0.0/19
ip4:172.217.32.0/20
ip4:172.217.128.0/19
ip4:172.217.160.0/20
ip4:172.217.192.0/19
ip4:172.253.56.0/21
ip4:172.253.112.0/20
ip4:108.177.96.0/19
ip4:35.191.0.0/16
ip4:130.211.0.0/22
[dereandor@manjaro Task11]$ ./epostsjekk.sh statoil.no

MX maskiner fra: statoil.no:
- Domene: statoil-no.mail.protection.outlook.com, IPv4: 104.47.9.36, IPv6: 104.47.10.36

SPF info:
Running spf_include on spf.protection.outlook.com
ip4:40.92.0.0/15
ip4:40.107.0.0/16
ip4:52.100.0.0/14
ip4:104.47.0.0/17
ip6:2a01:111:f400::/48
ip6:2a01:111:f403::/48
Running spf_include on spfd.protection.outlook.com
ip4:51.4.72.0/24
ip4:51.5.72.0/24
ip4:51.5.80.0/27
ip4:51.4.80.0/27
ip6:2a01:4180:4051:0800::/64
ip6:2a01:4180:4050:0800::/64
ip6:2a01:4180:4051:0400::/64
ip6:2a01:4180:4050:0400::/64
[dereandor@manjaro Task11]$ vim epostsjekk.sh 
[dereandor@manjaro Task11]$ vim oppgave1.md
[dereandor@manjaro Task11]$ 

